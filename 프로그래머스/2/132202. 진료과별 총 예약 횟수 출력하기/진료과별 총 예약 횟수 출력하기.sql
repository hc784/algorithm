-- 코드를 입력하세요
SELECT mcdp_cd as '진료과 코드', COUNT(*) as '환자수'
from appointment 
where DATE_FORMAT(APNT_YMD, '%y-%m') = '22-05'
group by mcdp_cd
order by 환자수, mcdp_cd ASC

#select DATE_FORMAT(apnt_ymd, '%y-%m') = '22-05' from APPOINTMENT;