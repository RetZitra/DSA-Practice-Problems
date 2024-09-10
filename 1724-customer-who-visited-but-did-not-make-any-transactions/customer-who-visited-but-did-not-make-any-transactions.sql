# Write your MySQL query statement below
-- subquery
-- Select customer_id,count(visit_id) as count_no_trans from Visits where visit_id not in(select visit_id from Transactions)group by customer_id;
-- join
select customer_id,count(visit_id)as count_no_trans from Visits where visit_id not in(select Transactions. visit_id from Visits INNER JOIN Transactions on 
Visits.visit_id=Transactions.visit_id)group by customer_id