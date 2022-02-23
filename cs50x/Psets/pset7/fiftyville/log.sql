 -- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = "Chamberlin Street"
Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

SELECT name FROM interviews WHERE day = 28 AND month = 7;
SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND name = "Jose";
transcript
“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”

SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND name = "Eugene";
transcript
1: “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”

2: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND name = "Barbara";
transcript
“You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address

SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND name = "Ruth";
transcript
Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND name = "Raymond";
transcript
As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.


##################

MADISON:
SELECT * FROM courthouse_security_logs WHERE year = 2020 AND day = 28 AND month = 7 ORDER BY hour;
268 | 2020 | 7 | 28 | 10 | 35 | exit | 1106N58

SELECT * FROM people WHERE license_plate = "1106N58";
id | name | phone_number | passport_number | license_plate
449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58 = 35

SELECT * FROM bank_accounts WHERE person_id = 449774
account_number | person_id | creation_year
76054385 | 449774 | 2015

SELECT * FROM atm_transactions WHERE account_number = 76054385;
id | account_number | year | month | day | atm_location | transaction_type | amount
266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60

id | caller | receiver | year | month | day | duration
SELECT * FROM phone_calls WHERE caller = "(286) 555-6063";
254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43 = 250277 | James | (676) 555-6554 | 2438825627 | Q13SVG6
284 | (286) 555-6063 | (310) 555-8568 | 2020 | 7 | 28 | 235 = 994229 | Angela | (310) 555-8568 | 9920757687 | SS458D7


SELECT * FROM passengers WHERE passport_number = 1988161715;
flight_id | passport_number | seat
36 | 1988161715 | 6D

SELECT * FROM flights WHERE id = 36;
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20

SELECT * FROM airports WHERE id = 8; = Fiftyville Regional Airport
SELECT * FROM airports WHERE id = 4; = Heathrow Airport


SELECT * FROM flights WHERE id = 21;
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
21 | 3 | 8 | 2020 | 7 | 26 | 17 | 58
SELECT * FROM flights WHERE id = 10;
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
10 | 8 | 4 | 2020 | 7 | 30 | 13 | 55
SELECT * FROM flights WHERE id = 47;
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
47 | 4 | 8 | 2020 | 7 | 30 | 9 | 46

SELECT * FROM flights WHERE id = 22;
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
22 | 1 | 8 | 2020 | 7 | 28 | 12 | 51

its not Madinson license_plate dosent match

Sometime within ten minutes of the theft max 10:25 min 10:15
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts  WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2020 AND day = 28 AND month = 7 AND atm_location = "Fifer Street")
Bobby
Danielle
Elizabeth
Ernest
Madison
Robert
Roy
Russell
Victoria

SELECT name FROM * WHERE passport_number IN AND name = "Ernest"(SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE year = 2020 AND day = 29 AND month = 7 AND hour < 9)) ORDER BY name;
Bobby
Danielle
Doris
Edward
Ernest
Evelyn
Madison
Roger

id  | year | month | day |	hour | minute |	activity | license_plate
260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95 = 221103 | Patrick | (725) 555-4692 | 2963008352 | 5P2BI95 (WAS NOT AT THE ATM, NOT HIM)
261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X = 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X  (CALL DOSENT MATCH) 
262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2 = 243696 | Amber | (301) 555-4174 | 7526138472 | 6P58WS2 (missing atm)
263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8 = 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8 (NO ACCOMPLICE)
264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7 = 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7 (missing atm)
265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ = 396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ (no flight)
266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE = 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE (no flight)
267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55 = 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55 (no atm)

##################

ERNEST:

SELECT * FROM phone_calls WHERE caller = "(367) 555-5533";
233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
236 | (367) 555-5533 | (344) 555-9601 | 2020 | 7 | 28 | 120
245 | (367) 555-5533 | (022) 555-4052 | 2020 | 7 | 28 | 241
285 | (367) 555-5533 | (704) 555-5790 | 2020 | 7 | 28 | 75
(375) 555-8161 = 864400 | Berthold | (375) 555-8161 |  | 4V16VO0 (WAS NOT IN FLIGHT, NOT HIM)
(344) 555-9601 = 985497 | Deborah | (344) 555-9601 | 8714200946 | 10I5658 (WAS NOT IN FLIGHT AND MORE THAN 1m, NOT HER)
(022) 555-4052 = 315221 | Gregory | (022) 555-4052 | 3355598951 | V4C670D (WAS NOT IN FLIGHT AND MORE THAN 1m, NOT HIM)
(704) 555-5790 = 652398 | Carl | (704) 555-5790 | 7771405611 | 81MZ921 (WAS NOT IN FLIGHT AND MORE THAN 1m, NOT HIM)


SELECT * FROM passengers WHERE passport_number = 5773159633;
flight_id | passport_number | seat
36 | 5773159633 | 4A
SELECT * FROM flights WHERE id = 36
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
36 | 8 | 4 | 2020 | 7 | 29 | 8 | 2

THE GODDAMN ACCOMPLICE WASN'T IN THE FLIGHT


