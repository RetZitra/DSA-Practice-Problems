# Write your MySQL query statement below
-- amk boleche je product je product gulo sell hoiche ta average bar korte to je product gulo sell hoiche segulo ami
-- unitssold e pabo tai 2to table join korte hobe using product_id ,ar oi joined table er sei tuple gulo chai jader
-- purchase date oi price table er oi product er price er date er moddhe thakche(start date ,end date)..tobei ami oi product
-- er price ta jante parbo karon produt er price ta date change hole onno rokhom hoi jacche..die ja ja dite boleche debo

-- amk ekhane left join korte hobe karon je product ta sold hoini tar o average price 0 dekhate hobe
-- joining condition ta date er on e dite hobe where e dile hobe na where e dile touple select kore to left join korchi left table er jei value gulo
-- te oi condition er value nei segulo bad chole jabe

-- COALESCSE use kora hoiche karon jei touple er value nei sei touple er upor aggegrate function lagale 0 ase..abr 0 die devide korle null chole ase 
-- tai null ele 0 korar jonno ota deoa

select p.product_id,COALESCE(ROUND(sum(p.price*u.units)/sum(units),2),0) as average_price from Prices as p left join
UnitsSold as u on p.product_id=u.product_id and u.purchase_date>=p.start_date and u.purchase_date<=p.end_date
group by p.product_id;