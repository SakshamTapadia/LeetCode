# Write your MySQL query statement below

select 'Low Salary' as category, count(account_id) as accounts_count
from Accounts 
where income < 2e4

union 

select 'Average Salary' as category, count(account_id) as accounts_count
from Accounts 
where income between 2e4 and 5e4

union 

select 'High Salary' as category, count(account_id) as accounts_count
from Accounts 
where income > 5e4