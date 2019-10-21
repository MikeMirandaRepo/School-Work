select distinct maker as "Makers of PCs Faster than 3"
from Product 
where model
in(select model from PC where speed > 3.0);

select distinct maker as "Makers of PCs Faster than 3"
from product
where exists(select * from PC 
	where Product.model = model and speed > 3.0);
    
    
select model as "Most Expensive Printer Model", price as "Price" 
from Printer
where price = (select max(price) from Printer);

select model as "Most Expensive Printer Model", price as "Price" 
from Printer 
where price >= all(select price from Printer);


select model as "Models of Faster PCs than Laptops"
from Laptop
where speed <= any(select speed from PC);

select Laptop.model as "Models of Faster PCs than Laptops"
from Laptop
where exists(select PC.speed from PC where PC.speed >= Laptop.speed);


select alll.model as "Most Expensive Model", alll.price as "Price"
from((select model,price from PC) 
	union
	(select model, price from Laptop)
    union
    (select model, price from Printer)) alll
where alll.price in(select max(allll.price) 
from ((select price from PC) 
	union
	(select price from Laptop)
    union
    (select price from Printer))allll);
    
select model as "Most Expensive Model", price as "Price"
from((select model,price from PC)  
	union 
    (select model,price from Laptop) 
    union 
    (select model,price from Printer)) allP 
where price >= all(select alll.price 
from((select model,price from PC)  
	union 
    (select model,price from Laptop) 
    union 
    (select model,price from Printer)) alll);



select distinct maker as "Cheapest Color Printer", Printer.price as "Price"
from Printer, Product 
where Printer.model = Product.model 
	and 
	color = true
    and
    price in(select min(price) from Printer);
    
select distinct maker as "Cheapest Color Printer", Printer.price as "Price"
from Product, Printer 
where color = true
	and 
    Printer.model = Product.model
    and 
    price <= all(select price from Printer);
    
    
select distinct maker as "Maker of Fastest speed from Lowest RAM"
from Product, PC
where Product.model = PC.model
	and 
    speed >= (select max(speed) 
			from PC where ram = (select min(ram) from PC));
            
select distinct maker as "Maker of Fastest speed from Lowest RAM"
from Product, PC
where Product.model = PC.model
	and 
    speed >= all(select speed from PC 
		where ram = 
			(select min(ram) from PC));

            





















