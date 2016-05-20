#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;
void sortFile();
int main(){
	sortFile();
}
void sortFile(){
	fstream fileRead;
	fstream fileWrite;
	vector<string> store;
	vector<int> x;
	int date = 0;
	int count = 0;
	string dateC = "";
	string dateY = "";
	string dateM = "";
	string dateD = "";
	string notes = "";
	string countS = "";
// write here Text to get each file to sort each file	
// new file	fileRead.open("Calendar.txt");
	//retrieves first line in text
	getline(fileRead >> ws, dateM, '/');
	getline(fileRead >> ws, dateD, '/');
	getline(fileRead >> ws, dateY, '|');
	getline(fileRead >> ws, notes);
	while (!fileRead.eof()) {
//		dateC = dateY.substr(0,4);
		//converts the counter to a string so it can be appended on to the end of the date variable to be called later
		if(count < 10){
			countS = "0" + to_string(count);
		}else if(count < 100){
			countS = to_string(count);
		}
		//adds the rest of the information to be sorted
		dateC += dateM + dateD + countS;
		//converet the string into a int
		istringstream(dateC) >> date;
		//stores information to vectors
		x.push_back(date);
		store.push_back(notes);
		//retrieves next line in text document
		getline(fileRead >> ws, dateM, '/');
		getline(fileRead >> ws, dateD, '/');
		getline(fileRead >> ws, dateY, '|');
		getline(fileRead >> ws, notes);
		count += 1;//A counter to keep track of which line from the text document is beign retrieved
	}//end while loop
	fileRead.close();
// new file	fileWrite.open("Calendar.txt");//reopens the file to be overwriten
	//sorts the array with the dates in it
	sort(x.begin(), x.end());
	//take the sorted data and write it to the code in date order
	for(int i = 0; i < x.size(); i += 1){
		//accesses the information to be broken up
		date = x[i];
		//starts break up of data to be used
		//converts the integer to a string
		countS = to_string(date);
		//breaks string into the day month and year
		dateY = countS.substr(0,4);
		dateM = countS.substr(4,2);
		dateD = countS.substr(6,2);
		//connects the date to the rest of the file
		countS = countS.substr(8,2);
		istringstream(countS) >> count;//convert back to a int
		//calls the title and notes of the event
		notes = store[count];
		//writes the entries back onto the file
		fileWrite << dateM << "/" << dateD << "/" << dateY << " | " << notes << '\n';
	}//end for loop
	fileWrite.close();
}//end sortFile