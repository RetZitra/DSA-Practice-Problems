# Write your MySQL query statement below
-- approah:oi user_id ta conformation e joto bar ache seta holo number of request
-- tai ekhane user_id,time ta primary key karon ekta user onek request korte pare
-- oi perticular user tar joto bar action confirmation seta tar number of conformation
-- to groupby id die ei 2tor count peye gelam ,seta devide kore round korbo 2 decimal point obdhi

-- first table tar sathe second table tar left join korte hobe karon je somosto user ra request koreni tara to ar confirmation table e thakbe na,so tader o dekhate hobe je tader rate o-0/null
-- jara request kore ni tader tao dekhate hobe to left join korte hobe
-- karon sob user er information signups table e ache ,confirmation table e khali jara request koreche tader data ache


select s.user_id,COALESCE(ROUND(count(case when c.action='confirmed' then 1 END)/NULLIF(count(c.action),0),2),0) as confirmation_rate from
 Signups as s left join Confirmations as c on s.user_id=c.user_id 
 group by user_id


-- NULLIF(count(c.action),0) eta use korlam karon sql e 0 die devide kora allow noi tai,count jeheto automatic null hole 0 return kore tai eta 0 na return kore null return kore
-- kichu null die devide hole seta null ei hoi 0/null=null karon jader c.action e ei null tader c.action=confirmed hobe ki kore
-- so jate jokhon 0/null hocche tokhon over all query ta jate null na return kore, 0 return kore tai COALESCE function use kora jate oi function use kore amra null ele seta ke 0 kore dite pari overall take

