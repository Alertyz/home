SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE title IN (SELECT title FROM people 
JOIN stars ON people.id = stars.person_id 
JOIN movies ON stars.movie_id = movies.id 
WHERE name LIKE "Kevin Bacon" AND birth = 1958)
EXCEPT
SELECT DISTINCT name FROM people WHERE name LIKE "Kevin Bacon";