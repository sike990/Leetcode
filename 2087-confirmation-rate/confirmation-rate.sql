# Write your MySQL query statement below
select s.user_id,
case
when round(sum(action = "confirmed")/count(s.user_id),2) is null then 0
 else round(sum(action = "confirmed")/count(s.user_id),2)
 end as confirmation_rate
from signups  as s left join
confirmations as c
on s.user_id = c.user_id
group by s.user_id ;

