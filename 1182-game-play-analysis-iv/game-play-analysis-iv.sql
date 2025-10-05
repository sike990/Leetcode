# Write your MySQL query statement below
select round(sum(x.rnk = 2 and datediff(x.event_date,x.min_date) = 1)/count(distinct player_id),2) as fraction
from (
select *, 
rank() over(partition by player_id order by event_date) as rnk,
min(event_date) over(partition by player_id) as min_date
from Activity
) as x;
#where x.rnk = 2 and datediff(day,x.event_date,x.min_date) = 1;
