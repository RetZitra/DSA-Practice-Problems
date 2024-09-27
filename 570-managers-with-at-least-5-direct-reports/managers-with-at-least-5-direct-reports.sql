# Write your MySQL query statement below
-- approach: employee table er groupby manager id die same manager id gulo chole asbe die manager id er count.jodi count ba ba 5 er beshi hoi
-- sei manager id ta lagbe
-- sei manager id ta die amk employee id bar korte hobe die sei employee er name janar jonno self join korte hobe oi table tar pasei
-- ei ekei table join korbo jader first table er manager id =second table er id die oi manager er ditails oi same row te chole asbe
-- die oi condition use kore oi row gulo filter korar por ami oi same row te second table er employee der name ba ja ja details chaibe 
-- seta die debo

-- left join kora uchit karon jader manager nei (null) seta final table e asbe na..kintu ekhane null jader manager tader details lagbe na
-- according to question left join nao korte pari..but korata good habit

--  select e2.name from Employee as e1 left join Employee as e2 on e1.id=e2.managerId where count(managerId)>=5 group by e1.managerId
-- aggregrate function where clause er sathe use kora jai na tokhon having use korte hoi
-- same jinis uporer tai where clause die use korechi niche having die use korechi

select e2.name from Employee as e1  join Employee as e2 on e1.managerId=e2.id group by e1.managerId having count(e1.managerId)>=5