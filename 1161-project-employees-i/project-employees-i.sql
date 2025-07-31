# Write your MySQL query statement below
select p.project_id , round(avg(t.experience_years),2) as average_years from Project p
left join employee t
on p.employee_id=t.employee_id
group by p.project_id;