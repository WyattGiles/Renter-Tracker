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
	string file = "";
	cout << "'stop' will end the program." << endl << endl;
	while(what != "stop"){
		cout << "What would you like to do?" << endl << 
		getline (cin, what);
		if (what == "add"){
//			write();
		}	
		else if (what == "new"){
//			write();
		}
		else if (what == "read"){
			cout << "What file do you want to read?" << endl; 		
		}
		else if (what == "stop"){
			return 0;
		}
		else{
			cout << "!Not an option!" << endl;
		}
	}
}