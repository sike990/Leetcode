# Write your MySQL query statement below
select distinct  id , ((
    select count(*)
    from RequestAccepted
    where accepter_id = rg.id
) +
(
    select count(*)
    from RequestAccepted
    where requester_id = rg.id
) ) as num
from (
    (select distinct requester_id as id
    from RequestAccepted
    )
    UNION
    (
        select distinct accepter_id as id
        from RequestAccepted
    )
) as rg
order by num desc
limit 1
