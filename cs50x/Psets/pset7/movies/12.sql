SELECT title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE name LIKE "Helena Bonham Carter"
INTERSECT
SELECT title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE name LIKE "Johnny Depp";