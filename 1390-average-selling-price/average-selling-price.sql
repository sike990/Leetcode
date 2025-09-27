# Write your MySQL query statement below
select p.product_id , 
case

when round(sum(u.units),2) is null then 0
else round(sum(p.price*u.units)/sum(u.units),2) 

end as average_price

from Prices as p
left join
UnitsSold as u
on p.product_id = u.product_id and  u.purchase_date  between p.start_date and p.end_date
group by p.product_id;

-- select *,sum(u.units)
-- from Prices as p
-- left join
-- UnitsSold as u
-- on p.product_id = u.product_id;