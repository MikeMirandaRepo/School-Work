select maker as "Distinct Makers", count(maker) as "Number of PC's" from product where type = 'pc' group by maker;

select max(laptop.screen) as "Largest Laptop Screen" from product join laptop where type = 'laptop' and product.maker = 'E';

select Average_Price, maker 
	from(select avg(price) as 'Average_Price', maker 
		from(select price, model from pc union select price,model from laptop union select price,model from printer) as Prices 
        join product where Prices.model = product.model group by maker) as p 
		where Average_Price > 200;