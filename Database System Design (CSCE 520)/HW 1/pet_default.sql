select * from pet where sex='f' 
order by name;

update pet
set name = current_user()
where owner = 'Gwen';

update pet
set name = 'Chirpy'
where owner = 'Gwen';

update pet
set death = NULL
where owner = 'Harold' AND name = 'Buffy';

select * from pet;