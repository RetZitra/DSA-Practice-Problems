# Write your MySQL query statement below
-- 2to table join using employee_id
-- group_by product_id korte hobe karon ek ekta project e kaj kore je somosto employee tader average experience years
-- bar korte bolecehe tai aggegrate function use korte hobe same project id er upor

select p.project_id,Round(avg(e.experience_years),2) as average_years
from Project as p join Employee as e on p.employee_id=e.employee_id group by p.project_id
