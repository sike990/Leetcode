# Write your MySQL query statement below
select s.user_id,case
 when round(sum(c.action = "confirmed") /count(s.user_id),2) is null then 0
 else round(sum(c.action = "confirmed") /count(s.user_id),2)
 end as confirmation_rate
from Signups as s
left join Confirmations as c
on s.user_id = c.user_id
group by s.user_id;