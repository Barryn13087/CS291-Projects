//Assignment 3.................................................................................................
//CS291 AddressBookProgram Copyright (c) 2015 Barindra Narinesingh. All rights reserved.

/* Please ignore the duplicate void and return functions, I wrote this code one way then editied it as per instructed.
The first half of the code uses the method i originally had in mind for the address book, The linked list portion 
had to be remade. There is a duplicate extPerson2 and instead of using addressbook name, i used stringlinkedlist
as the name to follow the notes while debuggging and troubleshooting.

The code is messy  but it works. It also outputs to a file named "assign3_Adds.txt" and reads the file as well.
*/


#include<iostream>
#include<string>
#include<algorithm>				//used for switch function
#include <fstream>				//tried to use external input/output*


using namespace std;

//.............................................................................................................

class personType {
public:
	void printNM()const { cout << firstName << " " << lastName << endl; };
	string getNM() { fullName = firstName + ' ' + lastName; return fullName; };
	void setName(string first, string last) { firstName = first; lastName = last; };
	string getFirstName()const { return firstName; };
	string getLastName()const { return lastName; };
	personType(string first = "insert first name", string last = "insert last name") { firstName = first; lastName = last; };


private:
	string fullName;
	string firstName;
	string lastName;
};

//.............................................................................................................

class extPersonType : public personType {

public:
	extPersonType() { friendfoefamily = 0; dPhonenumber = ""; };
	void setPersonType(int dIs, string dnumb) { friendfoefamily = dIs; dPhonenumber = dnumb; };
	void personIS() {
		if (friendfoefamily == 0) cout << ":associate: " << endl;
		else if (friendfoefamily == 1) cout << ":friend: " << endl;
		else cout << ":family: " << endl;
	};

	int personISA() {
		if (friendfoefamily == 0) return 0;
		else if (friendfoefamily == 1) return 1;
		else return 2;
	};

	string personISan() {									//added for linked list compatibility
		if (friendfoefamily == 0) return ":associate: ";
		else if (friendfoefamily == 1) return ":friend: ";
		else return ":family: ";
	};
	void getphoneNumber() { cout<< dPhonenumber<< " "; }			//changed from void to string for linked list compatibility
	string getPhoneN() { return dPhonenumber; }

private:
	int friendfoefamily;
	string dPhonenumber;
};

//.............................................................................................................
class dateType : public extPersonType {
public:

	void setDate(int month, int day, int year) { dMonth = month; dDay = day; dYear = year; };
	string getdob() { doB = dMonth + ' ' + dDay + ' ' + dYear; return doB; };
	int getDay()const { return dDay; };
	int getMonth()const { return dMonth; };
	int getYear()const { return dYear; };
	void printDT()const { cout << "DOB: " << dMonth << " .. " << dDay << " .. " << dYear << endl << endl; };
	dateType(int month = 1, int day = 1, int year = 1900) { dMonth = month; dDay = day; dYear = year; };

private:
	string doB;
	int dMonth;
	int dDay;
	int dYear;
};


//.............................................................................................................

class addressType : public dateType {

public:
	
	addressType(string info1a="", string info2a="", string info3a="", string info4a="") { dStreetAddress = info1a; dCity = info2a; dState = info3a; dZip = info4a; };
	void setAddressType(string info1, string info2, string info3, string info4) { dStreetAddress = info1; dCity = info2; dState = info3; dZip = info4; 
						dtotalAddress = dStreetAddress + " " + dCity + ", " + dState + " " + dZip;}
	void printentireAddress() { dtotalAddress = dStreetAddress + " " + dCity + ", " + dState + " " + dZip; cout << dtotalAddress << endl; }
	string returnAddress() { return dtotalAddress; }
private:
	string dStreetAddress;
	string dCity;
	string dState;
	string dZip;
	string dtotalAddress;
};

//.............................................................................................................

class addressBookType :public addressType {

public:
	void addEntry() {}; //reuse addressType from parent
	void deleteEntry() {}; //reuse addressType from parent
	void printAllEntries() {}; //reuse print from parent
	void sortEntries() {}; //by last name
	void printEntry() {}; //reuse entireAddress from parent
	void printFamily() {};
	void printFriends() {};
	void printAssociates() {};

private:

};
//...............................................................................................................

class extPersonType2 {
public:
	extPersonType2(){
	};

	extPersonType2(personType p, addressType a, dateType d,  string s){
		per = p;
		add = a;
		dat = d;
		phoneN = s;
	};

	personType getper() { return per; }
	addressType getadd() { return add; }
	dateType getdata() { return dat; }
	string getPhone() { return phoneN; }
	void print() { 
		getper().printNM();
		cout << " ";
		getadd().printentireAddress();
		cout << " ";
		getdata().printDT();
		cout << " ";
		getPhone();

	}

private:
	personType per;
	addressType add;
	dateType	dat;
	string phoneN;


};

//Creating linked list.............................................................................................................

class stringNode {					//textbook linked list, kept as is to follow easier.
									//I tired making a linked list under extPerson  with Name, Address and relation but it wouldn't work as intended
public:								//submitted as is due to deadline, added input/oupt files to make up for this.
private:
	extPersonType2 elem;
	stringNode* next;
	friend class stringLinkedList;
};


class stringLinkedList {

public:
	stringLinkedList() { head = NULL; };

	~stringLinkedList() {
		while (!empty()) {
			removeFront();
		}
	};

	bool empty() const { return (head == NULL); };

	void addFront(const extPersonType2& e) {
		stringNode*v = new stringNode;
		v->elem = e;
		v->next = head;
		head = v;
	};

	void removeFront() {
		stringNode*old = head;
		head = old->next;
		delete old;
	};

	void printList() {
		stringNode*p = head;
		while (p != NULL) {
			(p->elem).print();
			p = p->next;
		}
		cout << endl;
	};

private:
	stringNode* head;
};


//main program.............................................................................................................

int main() {

	addressBookType simplebookof[50];


	int select;
	string choice, c1, c2, c3, c4;

	//add to address book.............................................................................................................


	simplebookof[1].setName("john", "fatso");
	simplebookof[1].setAddressType("111_overdrive_rd", "overthehill", "DC", "12345.");
	simplebookof[1].setPersonType(0, "718-101-2222");
	simplebookof[1].setDate(1, 30, 2000);

	simplebookof[2].setName("bella", "grunts");
	simplebookof[2].setAddressType("11_adro_rd", "overthere", "NC", "12222.");
	simplebookof[2].setPersonType(0, "718-333-1111");
	simplebookof[2].setDate(2, 22, 2001);

	simplebookof[3].setName("asha", "euros");
	simplebookof[3].setAddressType("23_bway,", "oedve", "XC", "35643.");
	simplebookof[3].setPersonType(1, "718-111-1111");
	simplebookof[3].setDate(3, 31, 1999);

	simplebookof[4].setName("purr", "cat");
	simplebookof[4].setAddressType("muscial_rd", "bwast", "NY", "58212.");
	simplebookof[4].setPersonType(1, "212-363-4443");
	simplebookof[4].setDate(6, 11, 2001);

	simplebookof[5].setName("woof", "dog");
	simplebookof[5].setAddressType("0_runner", "digsalot", "AT", "10032.");
	simplebookof[5].setPersonType(2, "111-222-3333");
	simplebookof[5].setDate(4, 12, 1999);

	simplebookof[6].setName("getting", "Ridof");
	simplebookof[6].setAddressType("78 gone_overd", "aplace", "TN", "58264.");
	simplebookof[6].setPersonType(0, "568-263-6347");
	simplebookof[6].setDate(5, 6, 2002);



	//print every person in address book.............................................................................................................

	cout << "printing everyone in address book..............................................................................." << endl << endl;

	for (int x = 1; x <= 6; x++) {
		cout << x << ") ";
		simplebookof[x].printNM();
		simplebookof[x].printentireAddress();
		cout << " " << endl;
	}


	//deleting person in address book, should show default values..................................................................................

	cout << "deleting person 6 in address book, then printing to test............................................................" << endl << endl;

	simplebookof[6] = simplebookof[0]; //simplebookof[0] has default values, so by copying it, it erases the destination infomation
	simplebookof[6].printNM();
	simplebookof[6].printentireAddress();
	cout << " " << endl;

	//	for (int x = 1; x <= 5; x++) {					//use for loop to shift elements in beginning to middle of array after deleting
	//		simplebookof[x] = simplebookof[x + 1];
	//	}

	//sort the address book by name.............................................................................................................

	cout << "sorting names..................................................................................................." << endl << endl;

	string temp1, temp2, temp3;

	for (int y = 1; y <= 4; y++)			//bubble sort
		for (int x = 1; x <= 4; x++) {
			temp1 = simplebookof[x].getLastName();
			cout << temp1 << endl;			//prints out last name to see what it is comparing
			temp2 = simplebookof[x + 1].getLastName();
			cout << temp2 << endl << endl;


			if (temp1 > temp2) {
				swap(simplebookof[x], simplebookof[x + 1]);
				cout << "swapping the above.....................^ " << endl << endl;
			}
			else
				continue;
		}
	cout << "After sorting..................................................................................................." << endl << endl;

	for (int x = 1; x <= 5; x++) {
		cout << x << ") ";
		simplebookof[x].printNM();
		simplebookof[x].printentireAddress();
		cout << " " << endl;
	}

	//print all info on person in the book.............................................................................................................

	cout << "Printing address, phone number and DOB, use number to print info.........................................................................." << endl << endl;

	simplebookof[1].printNM();
	simplebookof[1].personIS();
	simplebookof[1].printentireAddress();
	simplebookof[1].getphoneNumber();
	simplebookof[1].printDT();

	//printing Associates.............................................................................................................

	cout << "Printing Associates.........................................................................." << endl << endl;

	for (int x = 1; x <= 5; x++) {
		int temp4;
		temp4 = simplebookof[x].personISA();
		if (temp4 == 0) {						// 0 for associate
			simplebookof[x].printNM();
			simplebookof[x].printentireAddress();
			simplebookof[x].personIS();
			cout << " " << endl;
		}
		else
			continue;
	}
	//printing friends.............................................................................................................

	cout << "Printing friends.........................................................................." << endl << endl;

	for (int x = 1; x <= 5; x++) {
		int temp4;
		temp4 = simplebookof[x].personISA();
		if (temp4 == 1) {						// 1 for friends
			simplebookof[x].printNM();
			simplebookof[x].printentireAddress();
			simplebookof[x].personIS();
			cout << " " << endl;
		}
		else
			continue;
	}
	//printing family.............................................................................................................

	cout << "Printing family.........................................................................." << endl << endl;

	for (int x = 1; x <= 5; x++) {
		int temp4;
		temp4 = simplebookof[x].personISA();
		if (temp4 == 2) {						// 2 for associate
			simplebookof[x].printNM();
			simplebookof[x].printentireAddress();
			simplebookof[x].personIS();
			cout << " " << endl;
		}
		else
			continue;
	}



//Using linked list for addresses and names.....................................................................................
//This entire section was redone, the other parts of the code will be edited and may show duplicate functions because
//the original way I wrote my code it used one string to hold everything in the linked list where as this one uses
//the class extPersonType2 to hold the individual elements of each person.

	cout << "adding names to linked lists.........................................................................." << endl << endl;
	cout << "linked list looks like addBookPeople[0] <--addBookPeople[1]<--addBookPeople[2]<--addBookPeople[3] " << endl << endl;
	
	personType person1N("Link", "Zelda");
	addressType person1A("Kokori", "Woods", "Hyrule", "98789.");
	dateType person1D(1, 30, 2000);
	extPersonType2 person1Whole(person1N, person1A, person1D, "718-929-4343");  //combines all 4 elements as per instructed
	

	personType person2N("Goku", "Saint");
	addressType person2A("Planet", "kai", "earth", "95689.");
	dateType person2D(4, 11, 2000);
	extPersonType2 person2Whole(person2N, person2A, person2D, "718-922-2333");
	
	personType person3N("Saiaman", "Baldy");
	addressType person3A("Code Dragon", "zone F", "Warth", "59812.");
	dateType person3D(1, 30, 2000);
	extPersonType2 person3Whole(person3N, person3A, person3D, "718-919-2111");
	
	
	stringLinkedList MylastAddressBook[3];
	MylastAddressBook[0].addFront(person1Whole);
	MylastAddressBook[1].addFront(person2Whole);
	MylastAddressBook[2].addFront(person3Whole);

	cout << "printing infomation in the linked lists.........................................................................." << endl << endl;

	MylastAddressBook[0].printList();
	MylastAddressBook[1].printList();
	MylastAddressBook[2].printList();

	cout << "\n\n deleting infomation in the linked lists.........................................................................." << endl << endl;

	cout << "printing person 3 " << endl<<endl;
	MylastAddressBook[2].printList();

	cout << "\n deleting person 3 " << endl << endl;
	MylastAddressBook[2].removeFront();
	cout << "\n\n there should be nothing shown above--^ " << endl;



			
			
	cout << "\n\n Opening external file for writing and  adding addresses.........................................................................." << endl << endl;

	ofstream dataFile1("assign3_Adds.txt", ios::app);	//opens file for writing

	string holds;
	for (int x = 1; x <= 5; x++) {
		dataFile1 << "" << endl << endl;
		dataFile1 << simplebookof[x].getFirstName() << " ";
		dataFile1 << simplebookof[x].getLastName() << " ";
		dataFile1 << simplebookof[x].returnAddress() << " ";
		cout << "adding addresses......" << x << "......" << endl;
	}

	dataFile1.close();				//closes file, must close.


	cout << "\n\n Opening external file for reading, file is in same folder as source file.........................................................................." << endl << endl;


	fstream dataFile("assign3_Adds.txt", ios::in);  // opens file for reading
	char input[10000];
	dataFile.getline(input, 10000, '$');
	cout << "\n";
	cout << input << endl;
	dataFile.getline(input, 10000, '$');

	dataFile.close();								//closes file, must close.








	cout << "\n\nEnd of program............................................................................................." << endl << endl;

	system("pause");
	return 0;
}