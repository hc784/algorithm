-- 코드를 입력하세요
select FOOD_TYPE,rest_id,rest_name,favorites 
from rest_info 
where (food_type, favorites) in (
select food_type, max(favorites)
from rest_info
group by FOOD_TYPE

)
order by FOOD_TYPE desc;
