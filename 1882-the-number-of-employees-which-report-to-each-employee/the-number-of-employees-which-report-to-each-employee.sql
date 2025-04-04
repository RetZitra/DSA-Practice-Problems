# Write your MySQL query statement below
-- amake dite hobe sei sob employee jader ke onno ra report koreche 1 bar er beshi
-- so amake each employee der data pete hobe, abar oi employee der kara kara report koreche tader data pete hobe
-- so report korar employee der id, ar employee der id ek ei table e ache to self join hobe


-- jodi amra table a er employee_id and table b er reports_to er respect e selfjoin kori
-- ar table a er employee_id ke group by kori, thle amra left table e each employee and right table e oi 
-- employee der kara kara report koreche seta peye jabo
-- ekhabe cheyeche je jei employee der report >1 tader ei nite
-- so group by korar pore oi grouped data er upor filter koar jonno having clause lagie bolbo je
-- jader number of report >0 amader sei sob employee id er group ei chai
-- ar baki jei jei column gulo cheyeche segulo print korbo
select a.employee_id,a.name,count(b.reports_to) reports_count,round(avg(b.age)) average_age
from Employees a join Employees b on a.employee_id=b.reports_to
group by employee_id having count(b.reports_to)>0 order by employee_id;