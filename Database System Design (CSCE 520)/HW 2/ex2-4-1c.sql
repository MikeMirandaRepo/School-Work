select pc.model, pc.price
from product, pc
where product.maker="B" and product.model = pc.model
union
select laptop.model, laptop.price
from product, laptop
where product.maker="B" and product.model = laptop.model
union
select printer.model, printer.price
from product, printer
where product.maker="B" and product.model = printer.model;