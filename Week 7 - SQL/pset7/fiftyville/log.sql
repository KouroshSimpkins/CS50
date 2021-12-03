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

SELECT hour, minute, origin_airport_id, destination_airport_id FROM flights 
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

