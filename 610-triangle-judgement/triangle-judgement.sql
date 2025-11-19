# Write your MySQL query statement below
select x , y , z , 
case
    when x >= z  and x >= y and  x < y+z then "Yes"
    when y >= x and y >= z and y < x+z then "Yes"
    when z >= y and z >= x and z < x+y then "Yes"
    else "No"
end as triangle
from Triangle