# Write your MySQL query statement below
SELECT s.student_id, s.student_name, su.subject_name, 
(SELECT COUNT(*) 
	FROM Examinations 
	WHERE student_id = s.student_id 
	AND subject_name = su.subject_name) AS attended_exams
FROM Students s
JOIN Subjects su
ORDER BY s.student_id, su.subject_name
