SELECT people.name FROM people, movies, stars
WHERE movies.title LIKE "Toy Story" AND movies.id=stars.movie_id AND people.id=stars.person_id;