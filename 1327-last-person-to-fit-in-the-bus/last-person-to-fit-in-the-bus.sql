# Write your MySQL query statement below
select q1.person_name
from Queue q1,Queue q2
where q2.turn <= q1.turn
group by q1.person_id , q1.person_name
having sum(q2.weight) <= 1000
order by q1.turn desc
limit 1
