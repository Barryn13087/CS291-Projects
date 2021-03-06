// Understanding Pointers

#include <iostream>
using namespace std;

int main() {

	int arr[10];			//Array decleration of size 10, type int (self evident)


	int* p; int* q;			//Creates pointers p and q (self evident)


	p = arr; *p = 10;		//assigns p to 1st place of array p=arr[0], then sets the value as 10
	cout << "arr[0]      "<< arr[0] << "	equals   " << *p << endl;  //proof
	
	q = &arr[5]; *q = 100;	//assigns q to 5th place of array, then sets the value to 100
	cout<< "arr[5]      " << arr[5] << "	equals   " << *q << endl;  //proof


	p++; *p = 20;			//changes the pointers place by one p=arr[1], then sets the value to 20
	cout << "arr[1]      " << arr[1] << "	equals   " << *p << endl;  //proof


	*(++q) = 200;			//changes the pointers place by one q=arr[6], then sets the value to 200
	cout << "arr[6]      " << arr[6] << "	equals   " << *q << endl;  //proof


	p = &arr[2]; *p = 30;	//assigns the address of arr[2] to pointer p, then assigns the value to 30
	cout << "arr[2]      " << arr[2] << "	equals   " << *p << endl;  //proof


	*(q++) = 300;			//assigns the value of pointer to (*q=300, *q=arr[6]), then changes the pointer place by one q=arr[7]
	cout << "arr[6]      " << arr[6] << "	does not equal   " << *q << endl;  //proof
	cout << "arr[7]      " << arr[7] << "	equals   " << *q << endl;  //proof
	

	p = arr + 3; *p = 40;	//assigns p to 3st place of array p=arr[3], then sets the value as 40
	cout << "arr[3]      "<< arr[3] << "	equals   " << *p << endl;  //proof

	
	*(++q) = 400;			//changes the pointers place by one q=arr[8], then assigns the value to 400
	cout << "arr[8]      " << arr[8] << "	equals   " << *q << endl;  //proof
	


	p = arr; *(p + 4) = 50; //assigns p to 1st place of array p=arr[0], then sets the value of arr[4] as 50 via *(p+4)
	cout << "arr[4]      "<< arr[4] << "	equals   " << *p << endl;  //proof



	q = q + 1; *q = 500; //changes the pointer q by one to *q=arr[9], then assigns the value to 500
	cout << "arr[9]      "<< arr[9] << "	equals   " << *q << endl;  //proof




		system("pause");
		
}
