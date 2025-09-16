# Write your MySQL query statement below
SELECT * FROM Users
WHERE REGEXP_LIKE(
    mail,
    '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$',  -- pattern
    'c'                                          -- 'c' = case-sensitive match
);
