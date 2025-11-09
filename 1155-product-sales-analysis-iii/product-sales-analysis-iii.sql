# Write your MySQL query statement below
select product_id , year as first_year , quantity , price
from (
select * , rank() over(partition by product_id order by year) as year_rank
from Sales
) as x
where year_rank = 1
;#Group by is executed before having