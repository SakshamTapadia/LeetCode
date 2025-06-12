# Write your MySQL query statement below
select *, IF(x+y>z and y+z>x and z+x>y, "Yes", "No") as triangle from Triangle