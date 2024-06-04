// Project4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HashTable.h"

using namespace std;

void test(); //This is written later to not complain

/*This function is used for my personal testing of just filling the array with random values*/
void fillIt(HashTable<Student> &table) {
	int col = 0;
	for (int i = 0; i < 1000; i++) {
		Student stu = Student(i, "A", "A", "A");
		table.insert(i, stu, col);
	}
}

/*This main method is used for a nice loop to create a database of students*/
int main()
{
	int done = 0;
	string input;
	HashTable<Student> table; //intializes the table for the class Student
	while (!done) {
		cout << "Would you like to (I)nsert or (D)elete a record, or (S)earch for a record, or (Q)uit?" << endl; //Gives them some options
		cout << "Enter action: "; //Asks for what they want to do
		cin >> input; //Get's what they want to do
		if (input == "I") { //Hey they want to insert someone!
			cout << "Inserting a new record." << endl;
			cout << "Last name: ";
			string last, first, year; //strings to hold the major important stuff
			int uid, collisions = 0; //gotta have a collisions variable for later
			cin >> last; //takes in their last name that we asked for earlier
			cout << "First name: ";
			cin >> first; //Takes in the first name
			cout << "UID: ";
			cin >> uid; //Takes in the UID
			while (cin.fail()) { //If taken in UID isn't an int then we have a problem and need to deal with it. Loop until they give us a proper UID.
				cout << "UID entered was not an int value." << endl;
				cin.clear(); //Empty cin
				cin.ignore(256,'\n'); //Ignore everything up until the next line
				cout << "Re-enter UID: ";
				cin >> uid; //Take in their new UID and if its still not an int lets do it again
			}
			cout << "Year: ";
			cin >> year; //Take in the year
			Student student = Student(uid, first, last, year); //Create a student with all of the given info
			if (table.insert(uid, student, collisions)) { //If it passes the insert then we can tell them it passed
				cout << "Record inserted." << endl;
			}
			else { //If it failed to insert then the record either already exists or the table is full
				cout << "Record failed to insert. Already exists or full table." << endl;
			}
		}
		else if (input == "D") { //They want to delete something!
			int uid;
			cout << "Enter UID to delete: ";
			cin >> uid; //Get the UID for them to delete
			while (cin.fail()) { //Same as above
				cout << "UID entered was not an int value." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Re-enter UID: ";
				cin >> uid;
			}
			cout << "Searching... ";
			if (table.remove(uid)) { //If we were able to remove it tell them so
				cout << "record found" << endl;
				cout << "Deleting... Complete" << endl;
			}
			else { //If we couldn't remove it then it probably doesn't exist
				cout << "record not found" << endl;
			}
		}
		else if (input == "S") { //They want to find/search something!
			int uid;
			Student returned; //This is the value we pass to the find method so it will set it equal to something if it exists
			cout << "Enter UID to search for: ";
			cin >> uid; //Take in the UID to find
			while (cin.fail()) { //Same as above
				cout << "UID entered was not an int value." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Re-enter UID: ";
				cin >> uid;
			}
			cout << "Searching... ";
			if (table.find(uid, returned)) { //If we were able to find it then take the value we passed it and print out all of its info
				cout << "record found" << endl;
				cout << "----------------------------" << endl;
				cout << "Last name: " << returned.lastName << endl;
				cout << "First name: " << returned.firstName << endl;
				cout << "UID: " << returned.uid << endl;
				cout << "Year: " << returned.year << endl;
				cout << "----------------------------" << endl;
			}
			else { //We couldn't find it so it probably doesn't exist
				cout << "record not found" << endl;
			}
		}
		else if (input == "Q") { //They want to leave me D:
			cout << "Exiting." << endl;
			done = 1; //Break the while loop
		}
		else if (input == "P") { //SHHHHHH... Don't tell anyone
			cout << "Secret print found!" << endl;
			cout << table << endl;
		}
		else { //Uhh I don't know what you typed in as an action. Try again!
			cout << "Command unknown." << endl;
		}
		cout << endl; //Adds a space to clean things up before the next command
	}
	return 0;
}

/*This is another function for my testing with more specifics so I didn't have to use the user input way*/
void test() {
	HashTable<Student> h1;
	int a = 0;
	int testUID = 834621;
	int testUID2 = 834622;
	int failUID = 834623;
	Student stu = Student(testUID, "John", "Doe", "Junior");

	//insert testing
	cout << "Insert testing" << endl;
	cout << "Should work since it doesn't exist." << endl;
	cout << h1.insert(testUID, stu, a) << endl;
	cout << "Shouldn't work since it does exist." << endl;
	cout << h1.insert(testUID, stu, a) << endl;
	cout << "Should work since it doesn't exist." << endl;
	cout << h1.insert(testUID2, stu, a) << endl;
	cout << endl;

	//Alpha test
	cout << "Alpha test" << endl;
	cout << h1.alpha() << endl;
	cout << endl;

	//Find Test
	cout << "Find test" << endl;
	Student value;
	cout << "Should work since it does exist." << endl;
	cout << h1.find(testUID, value) << endl;
	cout << "Should work since it does exist." << endl;
	cout << h1.find(testUID2, value) << endl;
	cout << "Shouldn't work since it doesn't exist." << endl;
	cout << h1.find(failUID, value) << endl;
	cout << endl;

	//remove testing
	cout << "Remove testing" << endl;
	cout << "Should work since it does exist." << endl;
	cout << h1.remove(testUID) << endl;
	cout << "Should work since it does exist." << endl;
	cout << h1.remove(testUID2) << endl;
	cout << "Shouldn't work since it doesn't exist." << endl;
	cout << h1.remove(failUID) << endl;
	system("PAUSE");
}
