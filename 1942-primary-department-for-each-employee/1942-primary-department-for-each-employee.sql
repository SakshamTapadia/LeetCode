# Write your MySQL query statement below
select emp.employee_id, emp.department_id
from Employee emp
where emp.primary_flag = 'Y'
group by emp.employee_id,emp.department_id
union all
select emp.employee_id,max(emp.department_id)
from Employee emp
group by emp.employee_id
having count(*) = 1