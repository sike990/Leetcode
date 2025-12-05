# Write your MySQL query statement below
#writing logic assuming there will be exactly one customer per day - fixed i will be using count >= 7 logic that will include all the customers -> but that did not work for the sum and average calculation
-- select  c1.visited_on , sum( c2.amount) as amount , round(sum(c2.amount)/7,2) as average_amount
-- from Customer c1
-- join Customer c2
-- on (DAY(c1.visited_on) - DAY(c2.visited_on)) >= 0 and (DAY(c1.visited_on) - DAY(c2.visited_on)) <= 6 and MONTH(c1.visited_on) = MONTH(c2.visited_on) and YEAR(c1.visited_on) = YEAR(c2.visited_on)
-- group by c1.visited_on
-- having count(c1.customer_id) >= 7
-- order by c1.visited_on asc

select visited_on,
(
    select sum(amount)
    from Customer
    where visited_on between DATE_SUB(c.visited_on,INTERVAL 6 DAY) and c.visited_on
) as amount,
(
    select round(sum(amount)/7,2) 
    from Customer
    where visited_on between DATE_SUB(c.visited_on,INTERVAL 6 DAY) and c.visited_on
) as average_amount
from Customer c
where c.visited_on >= (
    select DATE_ADD(min(visited_on),INTERVAL 6 DAY)
    from Customer
)
group by c.visited_on
order by c.visited_on


