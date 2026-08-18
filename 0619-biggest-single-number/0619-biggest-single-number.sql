# Write your MySQL query statement below
SELECT max(num ) AS num
FROM MyNumbers 
WHERE num in (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING count(*)=1 
);


