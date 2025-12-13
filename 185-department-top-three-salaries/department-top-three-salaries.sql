# Write your MySQL query statement below
with tab as (
select d.name as Department, e.name as Employee, salary as Salary,
dense_rank() over(partition by departmentId order by salary desc) as drank
from Employee e
join Department d
on d.id = e.departmentId
)
select Department,Employee,Salary
from tab 
where drank <= 3;
