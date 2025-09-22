# Write your MySQL query statement below
SELECT user_id AS id, COUNT(friend_id) AS num FROM
(SELECT requester_id AS user_id, accepter_id AS friend_id FROM 
RequestAccepted
UNION ALL
SELECT accepter_id AS user_id, requester_id AS friend_id FROM
RequestAccepted) AS all_friend
GROUP BY user_id
ORDER BY num DESC
LIMIT 1;