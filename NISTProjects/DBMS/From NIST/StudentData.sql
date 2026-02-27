drop table student;

create table STUDENT
(
	ROLLNUM	NUMBER(9),
	NAME	VARCHAR2(40),
	BRANCHCODE	VARCHAR(10),
	PHONE_NUM	VARCHAR(10)
);

drop table COURSES;

create table COURSES
(
	COURSECODE	VARCHAR2(10),
	COURSENAME	VARCHAR2(100),
	CREADITS	NUMBER(1)
);

drop table REGISTRATION;

create table REGISTRATION
(
	ROLLNUM	NUMBER(9),
	COURSECODE	VARCHAR2(10),
	REG_DATE	DATE,
	GRADE	CHAR,
	MAKES	NUMBER(5,2)
);

drop table BRANCH;

create table BRANCH
(
	BRANCHCODE	VARCHAR(10),
	BRANCHNAME	VARCHAR2(100)
);


insert into STUDENT values(201380001,'SUKANTA KUMAR GOUDA','CSE',9861983266);
insert into STUDENT values(201391002,'ANASUYA DEVI','ECE',9861055781);
insert into STUDENT values(201390011,'BIPLAB MAITI','EIE',9434408447);
insert into STUDENT values(201391012,'MONALISA MOHANTY','CSE',9439719006);
insert into STUDENT values(201391015,'ABHILASHA PRADHAN','CSE',9437064071);
insert into STUDENT values(201391016,'ETISHREE DALEI','ELE',9040434060);
insert into STUDENT values(201391018,'SANGITA RANI PANDA','ECE',9861888213);
insert into STUDENT values(201391025,'PADMALAYA SATPATHY','ECE',9438104685);
insert into STUDENT values(201390027,'SIBA PANIGRAHI','ELE',8093593815);
insert into STUDENT values(201391028,'PRIYAMBADA PRADHAN','ELE',8895033961);


insert into BRANCH values('CSE','Computer Science and Engineering');
insert into BRANCH values('ECE','Electronics and Communication Engineering');
insert into BRANCH values('ELE','Electrical and Electronics Engineering');
insert into BRANCH values('EIE','Electronics and Instrumentation Engineering');


insert into COURSES values('FEEC6302','Applied Physiology',3);
insert into COURSES values('PCEL4302','Electrical Machines-II',3);
insert into COURSES values('HSSM4430','Environmental Engineering',3);
insert into COURSES values('PEEC5402','Adaptive Signal Processing',3);
insert into COURSES values('CPME6304','Internal Combustion Engines and Gas Turbines',3);


insert into REGISTRATION values(201380001,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'A',78);
insert into REGISTRATION values(201391002,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'O',95);
insert into REGISTRATION values(201390011,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'E',85);
insert into REGISTRATION values(201391012,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'A',72);
insert into REGISTRATION values(201391015,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'C',55);
insert into REGISTRATION values(201391016,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'D',48);
insert into REGISTRATION values(201391018,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'B',65);
insert into REGISTRATION values(201391025,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'O',99);
insert into REGISTRATION values(201390027,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'E',85);
insert into REGISTRATION values(201391028,'FEEC6302',to_date('12-MAY-2014','dd-mon-yyyy'),'C',56);
insert into REGISTRATION values(201380001,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'A',78);
insert into REGISTRATION values(201391002,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'O',95);
insert into REGISTRATION values(201390011,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'E',86);
insert into REGISTRATION values(201391012,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'A',78);
insert into REGISTRATION values(201391015,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'C',56);
insert into REGISTRATION values(201391016,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'D',45);
insert into REGISTRATION values(201391018,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'B',68);
insert into REGISTRATION values(201391025,'CPME6304',to_date('12-MAY-2014','dd-mon-yyyy'),'O',98);
insert into REGISTRATION values(201390027,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'E',85);
insert into REGISTRATION values(201391028,'HSSM4430',to_date('12-MAY-2014','dd-mon-yyyy'),'C',56);
insert into REGISTRATION values(201380001,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'D',49);
insert into REGISTRATION values(201391002,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'B',65);
insert into REGISTRATION values(201390011,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'O',98);
insert into REGISTRATION values(201391012,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'E',85);
insert into REGISTRATION values(201391015,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'C',56);
insert into REGISTRATION values(201391016,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'A',78);
insert into REGISTRATION values(201391018,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'O',95);
insert into REGISTRATION values(201391025,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'E',85);
insert into REGISTRATION values(201390027,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'A',78);
insert into REGISTRATION values(201391028,'PEEC5402',to_date('12-MAY-2014','dd-mon-yyyy'),'C',58);

DROP TABLE foo;

create table foo
(
acol number,
bcol number,
ccol varchar2(20)
);

DROP TABLE Bar;
create table Bar
(
acol number,
ccol varchar2(20),
dcol number
);

insert into foo values(100,11,'APPLE');
insert into foo values(200,NULL,'APPLE');
insert into foo values(300,15,'CAT');
insert into foo values(400,NULL,'DOG');
insert into foo values(500,17,'EAGLE');
insert into foo values(600,15,'DOG');
insert into foo values(700,33,NULL);

INSERT INTO Bar VALUES(200,'APPLE',12);
INSERT INTO Bar VALUES(200,'ORANGE',NULL);
INSERT INTO Bar VALUES(400,'DOG',15);

INSERT INTO Bar VALUES(500,'FISH',16);
INSERT INTO Bar VALUES(700,'CAT',23);
INSERT INTO Bar VALUES(800,NULL,NULL);
INSERT INTO Bar VALUES(900,'BIRD',27);
INSERT INTO Bar VALUES(950,NULL,NULL);







