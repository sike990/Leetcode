select w1.id as Id
from Weather w1,
     Weather w2
where DATEDIFF(w1.recordDate , w2.recordDate) = 1 AND w2.temperature  < w1.temperature;