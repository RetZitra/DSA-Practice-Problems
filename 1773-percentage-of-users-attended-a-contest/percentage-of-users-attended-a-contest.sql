# Write your MySQL query statement below
-- eta holo select er moddhe subquery
-- amra each contest e koto jon perticipate korche seta pabo register table theke contest_id take group by kore 
-- but koto jon total user seta pabo amra users table theke
-- to percentage korar jonno ei second table er required data ta amr chai amra output e jei table ta bar korchi tar column er moddhe tai amra ekhane select er moddhe subquery likchi
-- to amadr jokhon ekta second table theke data answer table e cloumn e chai tokhon otake final table er select statement e likhbo
-- round function ta amder paramer e chai value and decimal places so 2 decimal point obdhi cheyeche bole setai korlam
-- ekhane orderby 2to korte holo percentage er respect e desending order e abr same percentage hole jar contest_id choto se age asbe so contest_id er respect e asending order e
select contest_id,round(((count(user_id)/(select count(user_id) from Users))*100),2) as percentage from Register group by contest_id order by percentage desc,contest_id;