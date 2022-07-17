SELECT title FROM movies WHERE id IN
(SELECT id FROM movies
JOIN stars
ON movies.id = stars.movie_id
WHERE person_id = (SELECT id FROM people WHERE name ="Johnny Depp")
INTERSECT
SELECT id FROM movies
JOIN stars
ON movies.id = stars.movie_id
WHERE person_id = (SELECT id FROM people WHERE name ="Helena Bonham Carter"));

--SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE movie_id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name ="Johnny Depp")) AND person_id IN (SELECT id FROM people WHERE name ="Helena Bonham Carter"));