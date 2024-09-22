# Write your MySQL query statement below 
-- join korar somoy jokhon 1 er beshi key thakbe tokhon erom bhabe korte hobe composite key
-- ON t1.machine_id=t2.machine_id and t1.process_id=t2.process_id
-- 1 er beshi condition e join korte hole erom korte hobe
-- where t1.activity_type='start' and t2.activity_type='end'
-- round up to 3 decimal point erom bolle ROUND(jeta round korte hobe,3(joto point obdhi))
-- ekhane ank starting ar ending time er difference bar korte boleche to ami self join kore ba diker table e 
-- sudhu starting time oi ek ei machine er ekei process er ar dan dike ending time rakhlam die ei ekei row er 2to timestamp 
-- er differece korle ami peye jacchi hocche oi process ta korte oi machine tar koto time laglo
-- die group by machine_id korchi to ek ek ta machine alada hoi galo tader process die die oi difference guloke average korle answer beroche
-- mne difference table e sudu ekta machine joto gulo process korche toto guloi difference ache to 
-- average korle oi machine er process time er average paoa galo
select  distinct t1.machine_id,ROUND(avg(t2.timestamp-t1.timestamp),3)as processing_time
from Activity as t1 join Activity as t2 
ON t1.machine_id=t2.machine_id and t1.process_id=t2.process_id 
where t1.activity_type='start' and t2.activity_type='end'
group by t1.machine_id