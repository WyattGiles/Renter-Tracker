//Renter Tracker
//By Wyatt Giles, Brandan Ivie, Tanner Davis
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;
void read ();
void write ();
void newwrite ();
void sortFile();
int main(){
	int menuOption = 0;
  	int exitVar = 1;
	do {
		//display menu and get option
		cout << endl;
		cout << "1 Read the file" << endl;
		cout << "2 Add to the file " << endl;
		cout << "3 Create a new file" << endl;
		cout << "4 End Program " << endl;
		cout << "Enter menu option: ";
		cin >> menuOption;
		cout << endl;
		cin.ignore();
		
		switch (menuOption){
			case 1:
				read();
				break;
			case 2:
				write();
				break;
			case 3:
				newwrite();
				break;
			case 4:
				exitVar = 0;
				break;
			default:
				cout << "Incorrect Opption" << endl;
				break;
		}

	} while (exitVar != 0);
	sortFile();
	return 0;
}//end main function
void read (){
	string file = "";
	string files = "";
	cout << "What file do you want to read?" << endl << endl;
	ifstream File ("Text");
	if (File.is_open()){
		while(!File.eof()){
			getline (File, files);
			cout << files << endl;
		}
	}
	File.close();
	cin >> file;
	cout << endl;
	ifstream whatfile (file);
	if (whatfile.is_open()){
		while(!whatfile.eof()){
			getline (whatfile, files);
			cout << files << endl;
		}
	}
	whatfile.close();
/*	{
		time_t currentTime;
		struct tm *localTime;

		time( &currentTime );                   // Get the current time
		localTime = localtime( &currentTime );  // Convert the current time to the local time

		int Day    = localTime->tm_mday;
		int Month  = localTime->tm_mon + 1;
		int Year   = localTime->tm_year + 1900;

		std::cout << "And the current date is: " << Day << "/" << Month << "/" << Year << std::endl;
	}*/
	 
}//end read function
void write (){
	cout << "What is the file name?" << endl;

	 
}//end write function
void newwrite (){
	string filename = "";
	string name = ""; // name of object
	string user = ""; // name of person
	string addr = ""; // address
	string date = ""; // when it will be back
	cout << "What is the new file's name?" << endl;
	cin >> filename;
	fstream file;
	file.open(filename, ios::app);
	cout << "What is the name of the item?" << endl;
	cin >> name;
	cout << "What is the constumers name?" << endl;
	cin >> user;
	cout << "What is their address?" << endl;
	cin >> addr;
	cout << "When will it be back? MM/DD/YYYY" << endl;
	cin >> date;
	file << name << endl << user << endl << addr << endl << date << "--------------------" << endl;
	file.close();
	fstream textfile;
	textfile.open("Text", ios::app);
	textfile << filename << endl;
	textfile.close();
	
}
void sortFile(){
}