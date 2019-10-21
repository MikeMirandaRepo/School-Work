
 drop table if exists Product, PC, Laptop, Printer;

 create database sales;
 
 use sales;
 
 create table Product(maker char(20), model char(20) primary key, type char(20));
 
 create table PC(model char(20) primary key, speed decimal(3,2), ram int, hd int, price decimal(8,2));
 
 create table Laptop(model char(20) primary key, speed decimal(4,2), ram int, hd int, screen decimal(3,1), price decimal(8,2));
 
 create table Printer(model char(20) primary key, color boolean, type char(10), price decimal(8,2));
 
 alter table printer drop color;
 
 alter table laptop add od char(10) default'none';