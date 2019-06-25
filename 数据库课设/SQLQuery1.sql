use master
go
create database COSSS
go
use COSSS
go
--�ֿ��

create table Base
(
Bno int primary key,
Bname  varchar(50) unique not null,
Bnum int,
Btel char(20) unique not null 
)
insert into Base values(01,'���ݿ�',100,'12345')
go
--�����
create table Goods
(
Gno int primary key,           --�����
Gname varchar(20) not null,    --������
Gprice int not null,          --���ﵥ��
Gbnum int references Base(Bno),--�������ڲֿ�
)
insert into Goods values(01,'����',1,01)

--���ű�
create table Department
(
Dno int primary key,--���ź�
Dname varchar(50)  not null,--������
Dtel char(20) unique not null, --������ϵ��ʽ
Daddr varchar(50) not null,   --���ŵ�ַ
)
insert into Department values(01,'��Ϣ��','123456','1����¥101�칫��')
insert into Department values(02,'������','123457','1����¥102�칫��')
insert into Department values(03,'��������','123458','1����¥103�칫��')
insert into Department values(04,'�˿͹���','123459','1����¥104�칫��')
go
--Ա����
create table Employe 
(
Eno int primary key,--Ա����
Ename varchar(50)  not null,--Ա����
Eage int not null,--Ա������
Ebno int references Department(Dno),  --Ա�����źŲ��ղ��ű���������ź�
Ework varchar(50) ,   --Ա����λ
Etel char(20) unique not null --Ա����ϵ��ʽ

)
insert into Employe values(222,'���� ', 20 , 02 ,'����ֿ�' ,'110120119')
insert into Employe values(333,'С�� ', 21 , 03 ,'������' ,'110120110')

go
--�˿ͱ�
create table Custom 
(
Cno int primary key,--�˿ͺ�
Cname varchar(20) not null,--�˿���
Ctle char(20) unique not null,--�˿���ϵ��ʽ
Caddr varchar(50) not null,  --�˿͵�ַ
)
insert into Custom values(01,'����','15486597325','�����һ��')
insert into Custom values(02,'����','15486597335','����ֶ���')
go
--����ϸ�ڱ�
  create table Detail
 (
 Dono int primary key ,    --��Ӧ������
 Dgno int references Goods(Gno),                 --�����
 Dgname varchar(20) ,      --������
 Dgprice  int ,  --���ﵥ���۸�
 Dgnum int not null,                              --��������
 )
insert into Detail values(01,01,'��˿',1,2)
--������
 create table Orders
(
Ono int references Detail(Dono) primary key,--������
Ocno int references Custom(Cno),--�����Ĺ˿ͺ�
Oeno int references Employe(Eno),--���������˱��
Oin varchar(10) not null,      --������Ӧ��Ʊ��
Omoney int not null,           --�����ܽ��
Opway varchar(30) not null,           --֧����ʽ
Opnum varchar(20),                    --֧���˺�
Odata varchar(30) not null,--��������
Ogddata varchar(30) not null,--��������
 )
 create table sump            
 (
 sumono int primary key,
 sumprice int
 )
 insert
 into sump(sumono,sumprice)
 select Dono,sum(Dgprice*Dgnum)
 from Detail
 group by Dono
 select * from Detail
 select * from sump
 
 declare @x int
set @x =(select sumprice from sump where sumono=01)
print @x
 insert into Orders values(01,01,333,'1234',@x,'���ÿ�','123456','2019.1.2','2019.1.3')
  select * from Orders
 go
 
 


---��¼��
create table logins
(

Demonum varchar(20) not null,
DemoPwd varchar(50) not null,
)
insert into logins values('admin','123')
insert into logins values('sn','123')
go

