# Write your MySQL query statement below
SELECT e_uni.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI e_uni
ON e.id = e_uni.id;