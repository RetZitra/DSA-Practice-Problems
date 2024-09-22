# Write your MySQL query statement below
-- jokhon ekta table ei 2to row er moddhe compare korte hoi tokhon self join korte hoi based upon some condition
-- ekhane table 1 ,ar table 2 join korbo amra chai table 1 e first date ta thak table 2 e next date ta thak tai 
-- table 1 er date-table 2 er date er difference hobe -1
-- ,ebar join hoi gele sekhan theke ja ja bar korar korte pari
-- ei join ta korar por t1 table e first date ta thakbe ar same row te t2 table e second date ta thakbe
-- DATEDIFF ta use koreo kora jai sekhane DATEDDIFF(t1.recordDate,t2.recordDate)=-1hobe
-- select t2.id from Weather as t1 JOIN Weather as t2 on t1.recordDate-t2.recordDate=-1 where t2.temperature>t1.temperature
-- | 1  | 2015-01-31 | 10          |
-- | 2  | 2015-02-01 | 25 
-- ei 2to date er difference ta bar korar jonno Datediff function ta lagbe emni te hobe na
select t2.id from Weather as t1 JOIN Weather as t2 on DATEDIFF(t1.recordDate,t2.recordDate)=-1 where t2.temperature>t1.temperature
