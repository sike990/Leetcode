# Write your MySQL query statement below
select  round(sum(case
when x.order_date = x.customer_pref_delivery_date and x.ranking = 1 then 1
else 0
end)*100/count(distinct x.customer_id),2) as immediate_percentage from (select *,
rank() over(partition by customer_id order by order_date) as ranking
from delivery) as x;

