SELECT title,rating FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE movie_id IN (SELECT id FROM movies WHERE year = 2010)
ORDER BY rating DESC, title ASC;