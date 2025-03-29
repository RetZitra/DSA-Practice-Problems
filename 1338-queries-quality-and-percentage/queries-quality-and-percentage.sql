# Write your MySQL query statement below
-- protita query er (rating/position) er  average chai setai holo quality
-- setai sum of each result(rating/position)/sum of number of result ,in each query


-- kono aggregate function er moddhe jokhon amra condition debo tokhon case use korte hobe, 
-- jetar group by korchi setar sob element concider na kore kichu element filter out kore tader upor aggregate function lagabe

-- ar having use kora hoi kono kichu ke group kore sei group hulor moddhe kichu kichu select korar jonno ba filter korar jonno

select query_name,round(avg(rating/position),2) as quality,
round(((count(case when rating<3 then rating else null end)/count(result))*100),2)
as poor_query_percentage from Queries group by query_name;

-- eta holo percentage er case ta ami each query er sei somostho result ke count korchi jader rating < 3 / total result each query er 
-- *100 percentage checyeche bole
-- round((sum(case when rating<3 then rating else null end)/sum(result))*100),2)