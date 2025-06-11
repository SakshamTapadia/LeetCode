# Write your MySQL query statement below
SELECT e.name
FROM Employee e
JOIN Employee f ON e.id = f.managerId
GROUP BY e.id, e.name
HAVING COUNT(f.id) >= 5;
