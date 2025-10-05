# Write your MySQL query statement below
select round(sum(order_date = customer_pref_delivery_date)*100/count(*),2) as immediate_percentage from(
select * ,
rank() over(partition by customer_id order by order_date) as rnk
from Delivery
) as x
where x.rnk = 1;