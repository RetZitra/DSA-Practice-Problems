# Write your MySQL query statement below
-- subquery methode e kora jai jokhon 2to table er ekta condition onno table e thake, kintu jei data gulo dekhate hoi seta ektai table e thake
-- join hoi jokhon 2to table er jeta data dekhate hoi seta 2to table milie ei thake
-- ekhane boleche jader bonus 2000 er theke kom tader dekhate so jader bonus nei(bonus=null) tader o dekhate hobe amr jader bonus 1000 theke kom tader dekhate hobe
-- tai left join korlam jate jader bonus nei tarao ase abr jader bonus 1000 er kom tarao ase ,ar jate null ta show hoi tao is null condition ta likhlam
select e.name,b.bonus from Employee as e LEFT JOIN Bonus as b on e.empId=b.empId where b.bonus is null or b.bonus<1000;