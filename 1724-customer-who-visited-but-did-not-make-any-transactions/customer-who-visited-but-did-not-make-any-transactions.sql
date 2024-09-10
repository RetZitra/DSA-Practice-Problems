# Write your MySQL query statement below
-- subquery
-- mne abr visits table theke sei sob visit id gulo chai jegilo transaction table e nei
-- inner query die korle age transaction table theke sob visitid gulo bar kore nebo die bolbo je amr visits table theke sei sob 
-- visit_id gulo chai jegilo transaction table e nei using not in command
-- ebar oi data gulo peye gele oi data er ki ki dekhate boleche sei gulo dekhabo
-- ekhane count ta customer er respect e groupby kore dekhate boleche
-- Select customer_id,count(visit_id) as count_no_trans from Visits where visit_id not in(select visit_id from Transactions)group by customer_id;
-- join
-- join dieo same bolchi je ami 2to table join kore nile jei visit_id gulo 2to table e common sei gulo thakbe ebr ami visits table er sei sob visit id bar korbo
-- jegolo ei join table e nei..sei sei data ba touple gulo peye gele ami nijer iccha moto data ja ja column dekhate bolbe segulo dekhabo
select customer_id,count(visit_id)as count_no_trans from Visits where visit_id not in(select Transactions. visit_id from Visits INNER JOIN Transactions on 
Visits.visit_id=Transactions.visit_id)group by customer_id