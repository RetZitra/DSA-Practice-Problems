# Write your MySQL query statement below
-- ekhane boleche jei sob students ra joto gulo exams dei tar count korte,to sudhu jodi ami students ar examinations table join kori to ami sudhu pabo jei somosto students ra
-- je je exam gulo dicche tar count,jei subject er exam gulo dicche na segulo ke pabo na,jei exam gulo dicche na sei exam gulokeo dekhate hobe je segulo 0 bar sicche ekta students

-- -- to output table e each subject, each students koto bar kore dieche seta thakbe ,exam na dielo thakbe (null hisabe)
-- -- to tai jate each students er pase each subject ase tai age ami subjects ar students cartesian product kore nilam

-- ebar dekte hobe 1st joined table er subject,ar student ei 2to same row er jonno koto gulo examination table e subject ache(not null) ache,joto gulo thakbe tar mane oi students toto bar oi subject e examination dieche
-- tai ei cartesian product table er sathe left join korlam exam table ke jate kore oi perticular joined table er student,subject er pase
-- oi examination table er oi pertcular student,subject ase ,ar je je examination table er subject null ache tar mane oi subject tar exam oi student dei ni 

-- ebr ami group by kore nilam students,subjects(1st joined table)karon tate sob subject ache die count korlam 
-- je ei grouped row gulo te koto gulo examination table er subject er value ache mne not null
-- karon count function  null value thakle tar count 0 dhore to tai examination table er subject er count korlam

-- die ebar jamon order by te dekhate boleche tamon dekhalam

-- left joi korlam karon examination table er jei subject ta null ache sei seta nischoi oi table e tar kono value chilo na kintu left join korechi bole ager joined table theke eseche mne
-- oi subject tai oi student ta exam deini
-- abr ekta students ekei subject onk bar dite pare,mne examinations table e ekei student,ekei subject onk bar thakte pare

-- su.subject_name=e.subject_name
-- eta korlam karon jehe to 1st joined table ta cross product korechi tai abr jokhon second table ta jurbo 
-- sekhane jate subject er 2to column e pasapasi same value thake,jamon id gulokeo same hote hobe


select st.student_id,st.student_name,su.subject_name,count(e.subject_name)as attended_exams
from (Students as st cross join Subjects as su) left join Examinations as e on st.student_id=e.student_id and su.subject_name=e.subject_name
group by st.student_id,su.subject_name order by st.student_id
