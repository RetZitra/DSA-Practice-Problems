# Write your MySQL query statement below
#referee id jader 2 noi tader name gulo to dekhate hobei + jader referee id null tader ta sob sobmoi hobe karon tara karur jonnoi reffered hoi ni
select name from Customer where referee_id is null or referee_id<>2;