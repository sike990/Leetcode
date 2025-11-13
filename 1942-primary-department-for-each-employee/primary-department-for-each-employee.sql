# Write your MySQL query statement below
select employee_id , department_id
from Employee as e1
where e1.primary_flag = "Y" or e1.employee_id in (
    select employee_id 
    from Employee
    group by employee_id
    having count(*) = 1
)
