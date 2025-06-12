# Write your MySQL query statement below
select e.employee_id, e.name, COUNT(e2.employee_id) as reports_count, ROUND(AVG(e2.age)) as average_age
from employees e2 join employees e
on e2.reports_to = e.employee_id
group by employee_id
order by employee_id