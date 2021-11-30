SELECT name FROM people
WHERE id IN (
    SELECT DISTINCT person_id FROM stars
    WHERE movie_id IN (
        SELECT movie_id FROM stars
        INNER JOIN people ON stars.person_id = people.id
        WHERE people.name = 'Kevin Bacon' AND people.birth = 1958
    )
)
AND NOT ( name = 'Kevin Bacon' AND people.birth = 1958 );