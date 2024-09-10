# Write your MySQL query statement below
-- jokhon erom hobe je 2to table er join kore je value gulo null sei gulo o dekhate hobe tar mane jeta 2to table e common nei seta charao onno value gulo o show korte hobe
-- tokhon amra jodi left table er extra value gulo dekhate bole left join right table er extra value gulo dekhate bole to right join ar both table er extra data dekthate bolle full outer join
-- marbo
select EmployeeUNI.unique_id,Employees.name from Employees LEFT JOIN EmployeeUNI on Employees.id=EmployeeUNI.id