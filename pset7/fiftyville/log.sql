--https://cs50.harvard.edu/x/2021/psets/7/fiftyville/
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street ="Chamberlin Street";
-- We need to know the id and the description in that particular crime.
-- we need all the clues in the withness
SELECT * FROM interviews WHERE month = 7 AND day = 28;


--Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND  day=28 AND hour = 10 AND minute >= 15 AND minute <= 25;
-- Output the name of the recorded license plate
-- the theft must be in this names
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND  day=28 AND hour = 10 AND minute >= 15 AND minute <= 25);


-- we need all the traction records in the atm that at located in "Fifer Street"  (withdraw money)
SELECT account_number FROM  atm_transactions WHERE year= 2020 AND month = 7 AND  day=28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw";
-- we need all the person_id that has the account_number we try to search
SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year= 2020 AND month = 7 AND  day=28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw");
-- Output the name of the people who make that transactions at that day
-- the name must be in the name
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year= 2020 AND month = 7 AND  day=28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"));



-- Find the original flight's airports id
SELECT id FROM airports WHERE city = "Fiftyville";
-- Find the earliest flight and output that destination's id
SELECT destination_airport_id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = 2020 AND month = 7 AND  day= 29 ORDER BY hour LIMIT 1;
-- Find the destination city
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = 2020 AND month = 7 AND  day= 29 ORDER BY hour LIMIT 1);


-- we need to know the flight id where the theft took
SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = 2020 AND month = 7 AND  day= 29 ORDER BY hour LIMIT 1;
-- the passport of all the passengers in the flight
-- the theft's passport are also included
SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = 2020 AND month = 7 AND  day= 29 ORDER BY hour LIMIT 1);


-- Output the phone calls that happened at that day
SELECT * FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;
-- Output the name of the reciver's name (the caller is the theft)
SELECT name FROM people WHERE phone_number = "(375) 555-8161";



-- Solve the Promblem using ONLY ONE LINE
-- Using the WHERE --- AND ---- AND ---AND to get the theft

SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND  day=28 AND hour = 10 AND minute >= 15 AND minute <= 25)
AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = 2020 AND month = 7 AND  day= 29 ORDER BY hour LIMIT 1))
AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year= 2020 AND month = 7 AND  day=28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"))
AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60);


-- the theft's Destination
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = 2020 AND month = 7 AND  day= 29 ORDER BY hour LIMIT 1);


-- the ACCOMPLICE is the receiver of the call
-- we first using the theft's name as a caller to search the phone table
-- The output above is the reciver's phone number
-- we the use the phone number to search the name of the accomplice
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE year = 2020  AND month = 7 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people
WHERE name = (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND  day=28 AND hour = 10 AND minute >= 15 AND minute <= 25)
AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = 2020 AND month = 7 AND  day= 29 ORDER BY hour LIMIT 1))
AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year= 2020 AND month = 7 AND  day=28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"))
AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60))));
