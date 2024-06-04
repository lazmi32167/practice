CREATE TABLE category(
id INT(11) PRIMARY KEY,
category_name VARCHAR(255),
description VARCHAR(255)    
);
CREATE TABLE books(
book_id INT(11) PRIMARY KEY,
book_title VARCHAR(255),
author_id INT,
publisher_id INT,
published_date DATE,   no_of_copies INT(11),
book_category INT,
FOREIGN KEY(author_id) REFERENCES authors(author_id),
FOREIGN KEY(publisher_id) REFERENCES publisher(publisher_id),
FOREIGN KEY(book_category) REFERENCES category(id)
);
CREATE TABLE booking(
booking_id INT(11) PRIMARY KEY,
book_id INT,
borrower_id INT,
bookingdate DATETIME,
availabledate DATE, 
FOREIGN KEY(book_id) REFERENCES books(book_id),
FOREIGN KEY(borrower_id) REFERENCES borrowers(borrower_id)
);    
CREATE TABLE borrow_book(
id INT PRIMARY KEY,   book_id INT, 
borrower_id INT,    
borrowingdate DATETIME,
duedate DATE,
FOREIGN KEY book_id REFERENCES books(book_id),
FOREIGN KEY borrower_id REFERENCES borrowers(borrower_id)
);  
CREATE TABLE return_book(
return_id INT PRIMARY KEY, 
borrow_id INT,    
return_date DATE,
FOREIGN KEY borrow_id REFERENCES borrow_book(book_id),
FOREIGN KEY borrower_id REFERENCES borrowers(borrower_id)
);  

 