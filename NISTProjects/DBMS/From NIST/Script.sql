
create table student
(
   roll number(3),
   name varchar2(50),
   branch varchar2(3),
   dob date
);

create table REGISTRATION		
(
   roll number(3),
   subject varchar2(50),
   grade varchar2(1)
);



insert into student values(101,'Allen','CSE',to_date('23.05.1986','dd.mm.yyyy'));
insert into student values(102,'Ward','ECE',to_date('10.06.1987','dd.mm.yyyy'));
insert into student values(103,'Blake','CSE',to_date('15.03.1987','dd.mm.yyyy'));
insert into student values(104,'Martin','IT',to_date('28.06.1988','dd.mm.yyyy'));
insert into student values(105,'Harvey','ECE',to_date('23.01.1986','dd.mm.yyyy'));
insert into student values(106,'Benjamin','CSE',to_date('11.01.1987','dd.mm.yyyy'));
insert into student values(107,'Smith','ECE',to_date('25.03.1987','dd.mm.yyyy'));
insert into student values(108,'Mohnish','IT',to_date('18.06.1988','dd.mm.yyyy'));
insert into student values(109,'James','IT',to_date('05.05.1990','dd.mm.yyyy'));
insert into student values(110,'Peter','CSE',to_date('03.09.1991','dd.mm.yyyy'));
insert into student values(111,'Michael','CSE',to_date('23.11.1986','dd.mm.yyyy'));
insert into student values(112,'Alice','ECE',to_date('10.06.1987','dd.mm.yyyy'));
insert into student values(113,'Alexander','IT',to_date('15.03.1987','dd.mm.yyyy'));
insert into student values(114,'Carol','ECE',to_date('28.06.1988','dd.mm.yyyy'));
insert into student values(115,'Jeff','CSE',to_date('23.12.1993','dd.mm.yyyy'));



insert into registration values(102,'CHM','O');
insert into registration values(105,'BIO','E');
insert into registration values(105,'PHY','O');
insert into registration values(106,'PHY','A');
insert into registration values(109,'BIO','A');
insert into registration values(105,'CHM','B');
insert into registration values(109,'CHM','E');
insert into registration values(109,'PHY','C');
insert into registration values(110,'PHY','A');
insert into registration values(111,'CHM','B');
insert into registration values(112,'BIO','O');
insert into registration values(113,'CHM','F');
insert into registration values(113,'PHY','F');
insert into registration values(115,'BIO','B');
insert into registration values(115,'CHM','D');
insert into registration values(115,'PHY','F');

