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
void sortFile();
void edit();
int main(){
	int menuOption = 0;
  	int exitVar = 1;
	do {
		//display menu and get options
		cout << endl;
		cout << "1 Read the file" << endl;
		cout << "2 Create an item" << endl;
//		cout << "3 Edit file" << endl;
		cout << "3 End Program " << endl;
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
/*			case 4:
				edit();
				break; 
*/
			case 3:
				exitVar = 0;
				break;
			default:
				cout << "Incorrect Opption" << endl;
				break;
		}

	} while (exitVar != 0);
//	sortFile();
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
}//end read function

void write (){
	string filename = "";
	string filecontents = "";
	bool x = true;
	string name = ""; // name of object
	string user = ""; // name of person
	string addr = ""; // address
	string date = ""; // when it will be back
	cout << "What is the file's name?" << endl;
	cin >> filename;
	fstream file;
	file.open(filename, ios::app);
	cout << "What is the name of the item?" << endl;
	cin.ignore(); // makes next line run
	getline (cin, name);
	cout << "What is the constumers name?" << endl;
	getline (cin, user);
	cout << "What is their address?" << endl;
	getline (cin, addr);
	cout << "When will it be back? MM/DD/YYYY" << endl;
	cin >> date;
	file << name << endl << user << endl << addr << endl << date << endl << "--------------------" << endl;
	file.close();
	fstream textfile;
	textfile.open("Text", ios::app);
	textfile << filename << endl;
//checks to see if filename is already written-can also use new function to write to a file
/*	while(!textfile.eof()){
		getline (textfile, filecontents);
		if(filecontents == filename){
			x = false;
		}
		if(x == true){
			textfile << filename << endl;
		}
	}
*/
	textfile.close();
}
/*
void edit(){
	string file = "";
	string files = "";
	string item = "";
	string read = "";
	cout << "What file do you want to edit?" << endl << endl;
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
	ifstream editfile (file);
	if (editfile.is_open()){
		while(!editfile.eof()){
			getline (editfile, files);
			cout << files << endl;
		}
	}
	// below this is what needs to be fixed for finding where the object is
	cout << "What item do you want to edit?";
	cin >> item;
	cout << endl;
	ifstream editfile (file);
	if (editfile.is_open()){
		while(!editfile.eof()){
			getline (editfile, item, "-------------------");
			cout << item << endl;
		}
	}
}
void sortFile(){
// will need to sort each file
	
}
*/