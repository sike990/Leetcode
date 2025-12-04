# Write your MySQL query statement below
(select u.name as results
from Users u
join MovieRating m 
on m.user_id = u.user_id
group by u.user_id
order by count(u.user_id) desc , u.name asc
limit 1)
union all
(select m.title as results
from Movies m
join MovieRating mr
on m.movie_id = mr.movie_id
where mr.created_at like "2020-02%"
group by m.movie_id
order by avg(rating) desc , m.title asc
limit 1)

