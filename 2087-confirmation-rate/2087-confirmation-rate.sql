# Write your MySQL query statement below
SELECT a.user_id, round(ifnull(avg(action = 'confirmed'), 0),2) as confirmation_rate
FROM Signups a
LEFT JOIN Confirmations b
ON a.user_id = b.user_id
GROUP BY a.user_id