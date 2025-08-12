select customer_id , COUNT(DISTINCT v.visit_id) as count_no_trans
from Visits AS v
LEFT JOIN
    Transactions AS t ON t.visit_id = v.visit_id
WHERE t.transaction_id IS NULL
GROUP BY customer_id
ORDER BY customer_id;
