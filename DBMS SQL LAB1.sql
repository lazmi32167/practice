CREATE DATABASE ecommerce2;
CREATE TABLE company(
comp_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(20),
contact VARCHAR(15) UNIQUE,    
address VARCHAR(50)    
);
INSERT INTO company
VALUES (NULL,"walton","+567484","Dhaka"), ("","singer","+9790","Barishal)
                                           
CREATE TABLE product(
pro_id INT PRIMARY KEY AUTO_INCREMENT,
name  VARCHAR(20),                                        
deccription VARCHAR(50) DEFAULT "No description",
unit_price DECIMAL(9,2),
quantity INT,
company_id INT,
FOREIGN KEY(company_id) REFERENCES company(comp_id)                                        
);                                           
 INSERT INTO product
VALUES (NULL,"laptop","",6745342.76,1,2)
                                           
 CREATE TABLE customer(
 cust_id INT PRIMARY KEY AUTO_INCREMENT,                                         
 name VARCHAR(15),
 phone VARCHAR(12) UNIQUE,
 address VARCHAR(40)                                          
  );                                          
 
INSERT INTO customer
VALUES (NULL,"lazmi","+567484","Dhaka")
                                           
 CREATE TABLE buyer(
 buyer_id INT PRIMARY KEY AUTO_INCREMENT,                                       
 cutomer_id INT,                                   
 pro_id INT,
 total_price DECIMAL(9,2),
 order_date DATE ,
 FOREIGN KEY(customer_id) REFERENCES customer(cust_id),
 FOREIGN KEY(pro_id) REFERENCES product(pro_id)                                       
 );                                          
 INSERT INTO buyer
VALUES (NULL,1,2,6759367.89,NULL)