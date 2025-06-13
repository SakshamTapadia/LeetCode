# Write your MySQL query statement below
with agg as (
select DepartmentId, Name, Salary, dense_rank() over (partition by DepartmentId order by Salary desc) as rnk
from Employee)

select d.Name as "Department", a.Name as "Employee", a.Salary as "Salary"
from agg a 
join Department d on a.DepartmentId = d.Id
where a.rnk < 4