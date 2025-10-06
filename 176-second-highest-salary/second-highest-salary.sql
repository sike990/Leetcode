# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestsalary
FROM employee
WHERE salary < (SELECT MAX(salary) FROM employee);