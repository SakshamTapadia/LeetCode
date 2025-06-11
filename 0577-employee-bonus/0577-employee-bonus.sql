# Write your MySQL query statement below
select e.name , b.bonus from Employee e LEFT JOIN Bonus b on e.empID = b.empId where b.bonus<1000 or b.bonus is null