select * from pet where sex='f' and birth > '1990-01-01'
order by name;

update pet
set name = current_user()
where owner = 'Gwen' and name = 'Whistler';

update pet
set death = curdate()
where owner = 'Harold' and name = 'Buffy';

select * from pet;
