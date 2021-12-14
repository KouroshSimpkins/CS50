-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Chamberlin Street';

-- 3 interviews, each transcript mentions the courthouse. The theft took place at 10:15 am.

SELECT name, transcript FROM interviews 
WHERE month = 7 AND day = 28;

-- Witnesses should be Raymond, Eugene, and Ruth

SELECT hour, minute, destination_airport_id FROM flights 
WHERE day = 29 AND month = 7 
ORDER BY hour, minute DESC;

SELECT id, full_name FROM airports 
WHERE city = 'Fiftyville'

-- Fiftyville id is 8, "fiftyville regional airport"

SELECT id, hour, minute, origin_airport_id, destination_airport_id FROM flights 
WHERE day = 29 AND month = 7
ORDER BY hour, minute DESC;

-- first flight out of fiftyville was at 8:20 am, and the destination airport was an airport with an id of 4.

SELECT full_name, city FROM airports WHERE id = 4;

-- Destination airport was Heathrow airport, the town/city is London.

SELECT atm_location, account_number, year FROM atm_transactions 
WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street';

/*
Returns a list of transactions that took place on the day from the atm on Fifer Street:

Fifer Street|28500762|2020
Fifer Street|28296815|2020
Fifer Street|76054385|2020
Fifer Street|49610011|2020
Fifer Street|16153065|2020
Fifer Street|86363979|2020
Fifer Street|25506511|2020
Fifer Street|81061156|2020
Fifer Street|26013199|2020
*/

SELECT person_id FROM bank_accounts 
WHERE account_number IN 
    (SELECT account_number FROM atm_transactions 
    WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street');

/*
Returns a list of people who have accounts at the bank with the account numbers:

686048
948985
514354
458378
395717
396669
467400
449774
438727

One of these people was the theif. We can cross reference passports to find out who the theif was.
The flight id was 4, so the thief was someone on flight number 4.
*/

SELECT id, name, passport_number FROM people 
WHERE id IN 
    (SELECT person_id FROM bank_accounts 
    WHERE account_number IN 
        (SELECT account_number FROM atm_transactions 
        WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street'));

/*
395717|Bobby|9878712108
396669|Elizabeth|7049073643
438727|Victoria|9586786673
449774|Madison|1988161715
458378|Roy|4408372428
467400|Danielle|8496433585
514354|Russell|3592750733
686048|Ernest|5773159633
948985|Robert|8304650265

I now have each individual's passport number and name.
*/

SELECT passport_number FROM passengers WHERE flight_id = 36;

/*
7214083635
1695452385
5773159633
1540955065
8294398571
1988161715
9878712108
8496433585
*/

SELECT id, name, passport_number FROM people 
WHERE id IN 
    (SELECT person_id FROM bank_accounts 
    WHERE account_number IN 
        (SELECT account_number FROM atm_transactions 
        WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street')
    AND passport_number IN(SELECT passport_number FROM passengers WHERE flight_id = 36));

/*
Returns 4 individuals who withdrew money from Fifer Street and then boared flight 36

395717|Bobby|9878712108
449774|Madison|1988161715
467400|Danielle|8496433585
686048|Ernest|5773159633

Cross reference these indivduals with the courthouse securityu logs to narrow down my list. 
Whoever it was left the courthouse by 10:25 am.
*/

SELECT day, hour, minute, activity, license_plate FROM courthouse_security_logs 
WHERE license_plate IN
    (SELECT license_plate FROM people 
    WHERE id IN 
        (SELECT person_id FROM bank_accounts 
        WHERE account_number IN 
            (SELECT account_number FROM atm_transactions 
            WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street')
        AND passport_number IN(SELECT passport_number FROM passengers WHERE flight_id = 36)))
AND day = 28 AND month = 7;

/*
Returns the time and activity of the security logs for the license plates of the people who boarded flight 36.

28|8|23|entrance|94KL13X
28|8|34|entrance|1106N58
28|9|14|entrance|4328GD8
28|10|18|exit|94KL13X
28|10|19|exit|4328GD8
28|10|35|exit|1106N58
*/

SELECT day, hour, minute, activity, courthouse_security_logs.license_plate, people.name, people.id FROM courthouse_security_logs, people
WHERE courthouse_security_logs.license_plate IN
    (SELECT license_plate FROM people 
    WHERE id IN 
        (SELECT person_id FROM bank_accounts 
        WHERE account_number IN 
            (SELECT account_number FROM atm_transactions 
            WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street')
        AND passport_number IN(SELECT passport_number FROM passengers WHERE flight_id = 36)))
AND day = 28 AND month = 7 AND people.license_plate = courthouse_security_logs.license_plate;

/*
28|8|23|entrance|94KL13X|Ernest|686048
28|8|34|entrance|1106N58|Madison|449774
28|9|14|entrance|4328GD8|Danielle|467400
28|10|18|exit|94KL13X|Ernest|686048
28|10|19|exit|4328GD8|Danielle|467400
28|10|35|exit|1106N58|Madison|449774
*/


-- Creates a table of suspects based on current evidence.
CREATE TABLE suspects
AS
SELECT DISTINCT courthouse_security_logs.license_plate, people.name, people.id FROM courthouse_security_logs, people
WHERE courthouse_security_logs.license_plate IN
    (SELECT license_plate FROM people 
    WHERE id IN 
        (SELECT person_id FROM bank_accounts 
        WHERE account_number IN 
            (SELECT account_number FROM atm_transactions 
            WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street')
        AND passport_number IN(SELECT passport_number FROM passengers WHERE flight_id = 36)))
AND day = 28 AND month = 7 AND minute < 25 AND people.license_plate = courthouse_security_logs.license_plate;

SELECT * FROM suspects;

/* returns:
94KL13X|Ernest|686048
4328GD8|Danielle|467400
*/

SELECT phone_calls.*, people.name FROM phone_calls, people
WHERE phone_calls.caller IN 
    (SELECT phone_number FROM people
    WHERE id IN (
        SELECT id FROM suspects))
AND day = 28 AND month = 7 AND year = 2020 AND people.phone_number = phone_calls.caller;

/*
233|(367) 555-5533|(375) 555-8161|2020|7|28|45|Ernest
236|(367) 555-5533|(344) 555-9601|2020|7|28|120|Ernest
245|(367) 555-5533|(022) 555-4052|2020|7|28|241|Ernest
285|(367) 555-5533|(704) 555-5790|2020|7|28|75|Ernest

This shows us that Ernest was the thief.

Now who was his accomplice? There are only 4 individuals it could be!

It's stated that the phone call took less than a minute. The only phone call that was less than a minute was the first one.

The number was (375) 555-8161. It was the phone number of the person who was the accomplice.
*/

SELECT name FROM people WHERE phone_number = '(375) 555-8161';

/* The accomplice was Berthold. */