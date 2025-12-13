# Write your MySQL query statement below
select u.user_id , CONCAT(UPPER(SUBSTRING(u.name,1,1)),LOWER((SUBSTRING(u.name,2,LENGTH(u.name)-1)))) as name
from Users u
order by u.user_id;