# Write your MySQL query statement below

-- eka writer ek er beshi book likhte pare abr se seta nije dekhte pare to ei query tai je je writer gulo 
-- nijei tader book dekheche seta eleo ekei 1 er beshi aste pare to sei jonno distinct keyword diechi jate 
-- dublicate na ase ar id asending order e sajate boleche tai sort korechi id er respect e
-- order by by default asending order e answer dei kintu descending order eo kora jai
-- ORDER BY column_name DESC;
select distinct author_id as id from Views where author_id=viewer_id order by author_id 