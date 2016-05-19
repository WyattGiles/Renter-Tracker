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
	cin >> file;
	{
		time_t currentTime;
		struct tm *localTime;

		time( &currentTime );                   // Get the current time
		localTime = localtime( &currentTime );  // Convert the current time to the local time

		int Day    = localTime->tm_mday;
		int Month  = localTime->tm_mon + 1;
		int Year   = localTime->tm_year + 1900;

		std::cout << "And the current date is: " << Day << "/" << Month << "/" << Year << std::endl;
	}
	 
}//end read function
void write (){
	cout << "What is the file name?" << endl;

	 
}//end write function
void newwrite (){
	string filename = "";
	string test = "";
	cout << "What is the new file's name?" << endl;
	cin >> filename;
	fstream file;
	file.open(filename, ios::app);
	cin >> test;
	file << test << endl;
	file.close();
	fstream textfile;
	textfile.open("Text", ios::app);
	textfile << filename << endl;
	textfile.close();
	
}