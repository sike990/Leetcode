# Write your MySQL query statement below
select s1.id,
case
when s1.id%2 = 0 then s3.student
when s1.id%2 <> 0 and s2.student is not null then s2.student
else s1.student
end as student
from Seat s1 
left join Seat s2
on s1.id = s2.id-1 
left join Seat s3
on s1.id-1 = s3.id