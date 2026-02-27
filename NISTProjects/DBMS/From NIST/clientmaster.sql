            CREATE TABLE CLIENT_MASTER( 
		CLIENTNO varchar2(6) PRIMARY KEY, NAME varchar2(20) NOT NULL, 
		ADDRESS1 varchar2(30), ADDRESS2 varchar2(30), 
		CITY varchar2(15), PINCODE number(8), STATE varchar2(15),
		BALDUE number(10,2), 
		CONSTRAINT ck_client CHECK (CLIENTNO like 'C%')
                                      );

	    CREATE TABLE PRODUCT_MASTER( 
		PRODUCTNO varchar2(6) PRIMARY KEY, 
		DESCRIPTION varchar2(15) NOT NULL, PROFITPERCENT number(4,2) NOT NULL, 
		UNITMEASURE varchar2(10) NOT NULL, QTYONHAND number(8) NOT NULL, 
		REORDERLVL number(8) NOT NULL, SELLPRICE number(8,2) NOT NULL, 
		COSTPRICE number(8,2) NOT NULL, 
		CONSTRAINT ck_product CHECK (PRODUCTNO like 'P%'), 
		CONSTRAINT ck_sell CHECK (SELLPRICE <> 0), 
		CONSTRAINT ck_cost CHECK (COSTPRICE <> 0)
                                        );

	    CREATE TABLE SALESMAN_MASTER
                 (
		SALESMANNO varchar2(6) PRIMARY KEY, 
		SALESMANNAME varchar2(20) NOT NULL, 
		ADDRESS1 varchar2(30) NOT NULL, Address2 varchar2(30), 
		CITY varchar2(20), PINCODE number(8), State varchar2(20), 
		SALAMT number(8,2) NOT NULL, 
		TGTTOGET number(6,2) NOT NULL, 
		YTDSALES number(6,2) NOT NULL, REMARKS varchar2(60), 
		CONSTRAINT ck_salesman CHECK (SALESMANNO like 'S%'), 
		CONSTRAINT ck_sal CHECK (SALAMT <> 0), 
		CONSTRAINT ck_target CHECK (TGTTOGET <> 0)
                );

	    CREATE TABLE SALES_ORDER
                                  ( 
		ORDERNO  varchar2(6) PRIMARY KEY, 
		CLIENTNO varchar2(6) REFERENCES CLIENT_MASTER, 
		ORDERDATE date, DELYADDR varchar2(25),  
		SALESMANNO varchar2(6)REFERENCES SALESMAN_MASTER, 
		DELYTYPE char(1) DEFAULT 'F', BILLEDYN char(1), 
		DELYDATE date, ORDERSTATUS varchar2(10), 
		CONSTRAINT ck_order CHECK (ORDERNO like 'O%'), 
		CONSTRAINT ck_dely_type CHECK (DELYTYPE IN ('P', 'F')), 
		CONSTRAINT ck_ord_status 
		CHECK(ORDERSTATUS IN ('In Process', 'Fulfilled', 'Backorder', 'Cancelled'))
                                  );


	    CREATE TABLE SALES_ORDER_DETAILS
                                    ( 
		ORDERNO varchar2(6) REFERENCES SALES_ORDER, 
		PRODUCTNO varchar2(6) REFERENCES PRODUCT_MASTER, 
		QTYORDERED number(8), QTYDISP number(8), PRODUCTRATE number(10,2), 
		PRIMARY KEY (ORDERNO, PRODUCTNO)
                                     );


	INSERT INTO Client_Master (ClientNo, Name, City, PinCode, State, BalDue) 
		VALUES ('C00001', 'Ivan Bayross', 'Mumbai', 400054, 'Maharashtra', 15000);
	INSERT INTO Client_Master (ClientNo, Name, City, PinCode, State, BalDue) 
		VALUES ('C00002', 'Mamta Muzumdar', 'Madras', 780001, 'Tamil Nadu', 0);
	INSERT INTO Client_Master (ClientNo, Name, City, Pincode, State, BalDue) 
		VALUES ('C00003', 'Chhaya Bankar', 'Mumbai', 400057, 'Maharashtra', 5000);
	INSERT INTO Client_Master (ClientNo, Name, City, PinCode, State, BalDue) 
		VALUES ('C00004', 'Ashwini Joshi', 'Bangalore', 560001, 'Karnataka', 0);
	INSERT INTO Client_Master (ClientNo, Name, City, PinCode, State, BalDue) 
		VALUES ('C00005', 'Hansel Colaco', 'Mumbai', 400060,  'Maharashtra', 2000);
	INSERT INTO Client_Master (ClientNo, Name, City, PinCode, State, BalDue) 
		VALUES ('C00006', 'Deepak Sharma', 'Mangalore', 560050, 'Karnataka', 0);

	INSERT INTO Product_Master 
		VALUES ('P00001', 'T-Shirts', 5, 'Piece', 200, 50, 350, 250);
	INSERT INTO Product_Master 
		VALUES ('P03453', 'Shirts', 6, 'Piece', 150, 50, 500, 350);
	INSERT INTO Product_Master 
		VALUES ('P06734', 'Cotton Jeans', 5, 'Piece', 100, 20, 600, 450);
	INSERT INTO Product_Master
		VALUES ('P07865', 'Jeans', 5, 'Piece', 100, 20, 750, 500);
	INSERT INTO Product_Master
	VALUES ('P07868', 'Trousers', 2, 'Piece', 150, 50, 850, 550);
	INSERT INTO Product_Master 
		VALUES ('P07885', 'Pull Overs', 2.5, 'Piece', 80, 30, 700, 450);
	INSERT INTO Product_Master 
		VALUES ('P07965', 'Denim Shirts', 4, 'Piece', 100, 40, 350, 250);
	INSERT INTO Product_Master 
		VALUES ('P07975', 'Lycra Tops', 5, 'Piece', 70, 30, 300, 175);
	INSERT INTO Product_Master 
		VALUES ('P08865', 'Skirts', 5, 'Piece', 75, 30, 450, 300);

	INSERT INTO Salesman_Master VALUES ('S00001', 'Aman', 'A/14', 'Worli', 'Mumbai', 400002, 'Maharashtra', 3000, 100, 50, 'Good');
	INSERT INTO Salesman_Master VALUES ('S00002', 'Omkar', '65', 'Nariman', 'Mumbai', 400001, 'Maharashtra', 3000, 200, 100, 'Good');
	INSERT INTO Salesman_Master VALUES ('S00003', 'Raj', 'P-7', 'Bandra', 'Mumbai', 400032, 'Maharashtra', 3000, 200, 100, 'Good');
	INSERT INTO Salesman_Master VALUES ('S00004', 'Ashish', 'A/5', 'Juhu', 'Bombay', 400044, 'Maharashtra', 3500, 200, 150, 'Good');

--delete from Sales_Order_Details;
--delete from Sales_Order;

	INSERT INTO Sales_Order (OrderNo, OrderDate, ClientNo, DelyType, BilledYn, SalesmanNo, DelyDate, OrderStatus) 
		VALUES('O19001', '12-june-02', 'C00001', 'F', 'N', 'S00001', '20-july-02', 'In Process');
	INSERT INTO Sales_Order (OrderNo, OrderDate, ClientNo, DelyType, BilledYn, SalesmanNo, DelyDate, OrderStatus) 
		VALUES('O19002', '25-june-02', 'C00002', 'P', 'N', 'S00002', '27-july-02', 'Cancelled');
	INSERT INTO Sales_Order (OrderNo, OrderDate, ClientNo, DelyType, BilledYn, SalesmanNo, DelyDate, OrderStatus) 
		VALUES('O19003', '18-feb-02', 'C00003', 'F', 'Y', 'S00003', '20-feb-02', 'Fulfilled');
	INSERT INTO Sales_Order (OrderNo, OrderDate, ClientNo, DelyType, BilledYn, SalesmanNo, DelyDate, OrderStatus) 
		VALUES('O46865', '03-apr-02', 'C00001', 'F', 'Y', 'S00001', '07-apr-02', 'Fulfilled');
	INSERT INTO Sales_Order (OrderNo, OrderDate, ClientNo, DelyType, BilledYn, SalesmanNo, DelyDate, OrderStatus) 
		VALUES('O46866', '20-may-02', 'C00004', 'P', 'N', 'S00002', '22-may-02', 'Cancelled');
	INSERT INTO Sales_Order (OrderNo, OrderDate, ClientNo, DelyType, BilledYn, SalesmanNo, DelyDate, OrderStatus) 
		VALUES('O19008', '24-may-02', 'C00005', 'F', 'N', 'S00004', '26-july-96', 'In Process');

--delete from Sales_Order_Details;

	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O19001', 'P00001', 4, 4, 525);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O19001', 'P07965', 2, 1, 8400);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O19001', 'P07885', 2, 1, 5250);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O19002', 'P00001', 10, 0, 525);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O46865', 'P07868', 3, 3, 3150);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O46865', 'P07885', 3, 1, 5250);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O46865', 'P00001', 10, 10, 525);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O46865', 'P03453', 4, 4, 1050);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O19003', 'P03453', 2, 2, 1050);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O19003', 'P06734', 1, 1, 12000);

        INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O46866', 'P07965', 1, 0, 8400);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O46866', 'P07975', 1, 0, 1050);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O19008', 'P00001', 10, 5, 525);
	INSERT INTO Sales_Order_Details (OrderNo, ProductNo, QtyOrdered, QtyDisp, ProductRate) 
		VALUES('O19008', 'P07975', 5, 3, 1050);


