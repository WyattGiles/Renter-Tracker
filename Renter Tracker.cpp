//Renter Tracker
//By Wyatt Giles, Brandan Ivie, Tanner Davis
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;
void read ();
void write ();
void newwrite ();
int main(){
	string what = "";
	cout << "'stop' will end the program." << endl << endl;
	while(what != "stop"){
		cout << "What would you like to do?" << endl << "add, new, read" << endl;
		getline (cin, what);
		if (what == "add"){
			write();
		}	
		else if (what == "new"){
			newwrite();
		}
		else if (what == "read"){
			read();		
		}
		else if (what == "stop"){
			return 0;
		}
		else{
			cout << "!Not an option!" << endl;
		}
	}
}//end main function
void read (){
	string file = "";
	cout << "What file do you want to read?" << endl;
	
}//end read function
void write (){
	cout << "What is the file name?" << endl;
}//end write function
void newwrite (){
	cout << "What is the new file's name?" << endl;
}