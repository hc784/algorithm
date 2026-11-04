-- 코드를 입력하세요 car id를 기준으로 그룹 바이? where로 대여중인것만 찾아서, in으로 대여중인 carid case when으로 대여중, 아니면 대여 가능.
# select when carId 디스팅트로 전부 출력. 해당 car id가 in에 있으면 대여중 아니면 

select distinct car_id, case when car_id in  
(SELECT CAR_ID 
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where date_format(start_date,'%y-%m-%d') <= '22-10-16' and date_format(end_date,'%y-%m-%d')>= '22-10-16') then '대여중'
else '대여 가능'
end as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
order by car_id desc

# group by car_id
# having
# order by


# case 
# when date_format(start_date,''%y-%m-%d') <= '22-10-16' && date_format(end_date,''%y-%m-%d')>= '22-10-16' then '대여중'
# when not(date_format(start_date,''%y-%m-%d') <= '22-10-16' && date_format(end_date,''%y-%m-%d')>= '22-10-16') then '대여 가능'
# end as 'AVAILABILITY'
# from
# where
# group by
# having
# order by