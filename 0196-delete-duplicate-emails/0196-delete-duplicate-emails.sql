DELETE p
FROM Person p 
JOIN Person q ON p.email = q.email
WHERE p.id > q.id;