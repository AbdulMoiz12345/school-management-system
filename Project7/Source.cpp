#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<cstdio>
#include<iomanip>
#include <windows.h>
using namespace std;
const int BLACK = 0;
const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int MAGENTA = 5;
const int YELLOW = 6;
const int WHITE = 7;
const int GRAY = 8;

void setColor(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
class answer
{
	char anss[70];
	string id;
public:
	void getanswer();
	void setid();
	string getid();
	void getidone(string idd);
	void displayans();
};

void answer::getanswer()
{
	cin.getline(anss, 69);
}

void answer::setid()
{
	cout << "enter id" << endl;
	cin >> id;
}

string answer::getid()
{
	return id;
}

void answer::getidone(string idd)
{
	id = idd;
}
void answer::displayans()
{
	const int width = 80; // total width of output
	const int idWidth = 20; // width reserved for ID

	// Create separator line
	string separatorLine(width, '-');

	// Display answer information
	cout << separatorLine << endl;
	cout << "ID: " << setw(idWidth) << left << id << endl;
	cout << "Answer given:" << endl;
	cout << anss << endl;
	cout << separatorLine << endl;
}
class quiz {
public:
	char* statement;

public:
	quiz() : statement(new char[50]) {}
	~quiz() { delete[] statement; }
	void getdata();
	void getdataforone();
	void display();
};

void quiz::getdata() {
	string section, sub;
	cout << "Enter the section for quiz: ";
	cin >> section;

	cout << "Enter the subject for quiz: ";
	cin >> sub;

	fstream fout("quizseclist", ios::app);
	fout << section + sub << endl;
	fout.close();

	cin.ignore();

	cout << "Type down the quiz: " << endl;
	cin.getline(statement, 49);
	cout << statement << endl;

	ofstream fout1;
	fout1.open(section + sub, ios::out | ios::binary);
	if (fout1.is_open()) {
		fout1.write(statement, strlen(statement));
		fout1.close();
	}
	else {
		cout << "Error opening file." << endl;
	}
}

void quiz::getdataforone() {
	string id;
	cout << "Enter the ID for quiz: ";
	cin >> id;

	fstream fout2("quizstulist", ios::app);
	fout2 << id << endl;

	cin.ignore();

	cout << "Type down the quiz: ";
	cin.getline(statement, 49);

	ofstream fout;
	fout.open(id, ios::out | ios::binary);
	if (fout.is_open()) {
		fout.write(statement, strlen(statement));
		fout.close();
	}
	else {
		cout << "Error opening file." << endl;
	}
}

void quiz::display() {
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << "Quiz statement: " << statement << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
}




class assignment
{
	char statement[50];
public:
	void getdata();
	void getdataforoneass();
	void display();
};
void assignment::getdata()
{
	int c1 = 0;
	string section;
	string subject;
	string l;
	cout << "Enter the section for assignment " << endl;
	cin >> section;
	cout << "Enter the subject" << endl;
	cin >> subject;
	string s = section + subject;
	ofstream fout;
	fout.open("assseclist", ios::app);
	fout << s << endl;
	fout.close();
	cin.ignore();
	cout << "Type down assignment " << endl;
	cin.getline(statement, 49);
	assignment c;
	ofstream fout1;
	string seet;
	seet = s + "assignment";
	fout1.open(seet, ios::out | ios::binary | ios::app);
	fout1.write((char*)this, sizeof(class assignment));
	fout1.close();
}

void assignment::getdataforoneass()
{
	assignment a;
	string id, sub;
	cout << "Enter the id for assignment " << endl;
	cin >> id;
	cout << "Enter subject" << endl;
	cin >> sub;
	fstream fout2("assstulist", ios::app);
	fout2 << id + sub << endl;
	cin.ignore();
	cout << "Type down assignment " << endl;
	cin.getline(statement, 49);
	ofstream fout;
	fout.open(id + sub + "assignment", ios::out | ios::binary);
	fout.write((char*)this, sizeof(class assignment));
	fout.close();
}

void assignment::display()
{
	cout << "--------------------------------------------------------" << endl;
	cout << "Assignment: " << statement << endl;
	cout << "--------------------------------------------------------" << endl;
}
#include <iostream>
#include <fstream>
using namespace std;

class marks
{
private:
	int mark;
	string id;

public:
	void setid(string idd);
	string getid();
	void getmarksdata();
	void getmarksdataone();
	void getmarkdataass();
	void getmarksdataassone();
	void showmarks();
};

void marks::setid(string idd)
{
	id = idd;
}

string marks::getid()
{
	return id;
}

void marks::getmarksdata()
{
	string section, sub;
	cout << "Enter section: ";
	cin >> section;
	cout << "Enter subject: ";
	cin >> sub;
	cin.ignore();

	cout << "Enter marks for this quiz/assignment: ";
	cin >> mark;
	cin.ignore();

	ofstream foutt;
	string filename = "marks" + section + sub;
	foutt.open(filename, ios::out | ios::app | ios::binary);

	if (!foutt)
	{
		cout << "Error opening file." << endl;
		return;
	}

	foutt.write(reinterpret_cast<char*>(this), sizeof(marks));
	foutt.close();

	ofstream fout2("markseclist", ios::app);
	fout2 << section + sub << endl;
	fout2.close();
}


void marks::getmarksdataone()
{
	cout << "Enter ID: ";
	cin >> id;
	cin.ignore();

	cout << "Enter marks for this quiz/assignment: ";
	cin >> mark;
	cin.ignore();

	ofstream foutt;
	string filename = "marks" + id;
	foutt.open(filename, ios::out | ios::app | ios::binary);

	if (!foutt)
	{
		cout << "Error opening file." << endl;
		return;
	}

	foutt.write(reinterpret_cast<char*>(this), sizeof(marks));
	foutt.close();

	ofstream fout2("markseclistone", ios::app);
	fout2 << id << endl;
	fout2.close();
}


void marks::getmarkdataass()
{
	string section, sub;
	cout << "Enter section: ";
	cin >> section;
	cout << "Enter subject: ";
	cin >> sub;
	cin.ignore();

	cout << "Enter marks for this quiz/assignment: ";
	cin >> mark;
	cin.ignore();

	ofstream foutt;
	string filename = "marksass" + sub + section;
	foutt.open(filename, ios::out | ios::app | ios::binary);

	if (!foutt)
	{
		cout << "Error opening file." << endl;
		return;
	}

	foutt.write(reinterpret_cast<char*>(this), sizeof(marks));
	foutt.close();

	ofstream fout2("markassseclist", ios::app);
	fstream ifin("markassseclist", ios::in);

	string line;
	bool exists = false;
	while (getline(ifin, line))
	{
		if (line == section + sub)
		{
			exists = true;
			break;
		}
	}
	if (!exists)
	{
		fout2 << section + sub << endl;
	}

	fout2.close();
}


void marks::getmarksdataassone()
{
	string sub;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter the subject: ";
	cin >> sub;
	cout << "Enter marks for this quiz/assignment: ";
	cin >> mark;
	cin.ignore();

	ofstream foutt;
	string filename = "marksassone" + id + sub;
	foutt.open(filename, ios::out | ios::app | ios::binary);

	if (!foutt)
	{
		cout << "Error opening file." << endl;
		return;
	}

	foutt.write(reinterpret_cast<char*>(this), sizeof(marks));
	foutt.close();
}


void marks::showmarks() {
	cout << "ID: " << id << std::endl;
	cout << "Marks obtained: " << mark << std::endl;
}
class attendence {
protected:
	string name;
	string id;
	int tdays;
	int present;

public:
	void setname();
	void setid();
	void setpresent(int p);
	void settotaldays(int k);
	std::string getid();
	int getpresent();
	int gettotaldays();
	void attendenceshow();
};

void attendence::setname() {
	cout << "Enter name: ";
	cin >> name;
}

void attendence::setid() {
	cout << "Enter ID: ";
	cin >> id;
}

void attendence::setpresent(int p) {
	present = p;
}

void attendence::settotaldays(int k) {
	tdays = k;
}

string attendence::getid() {
	return id;
}

int attendence::getpresent() {
	return present;
}

int attendence::gettotaldays() {
	return tdays;
}

void attendence::attendenceshow() {
	cout << "Name: " << name << "    ID: " << id << "    Present: " << present << "  Total days: " << tdays << std::endl;
}

class datesheet {
private:
	string date;
	string subject;
	string time;

public:
	void setdate();
	void setsubject();
	void settime();
	void display();
};

void datesheet::setdate() {
	cout << "Enter the date in this format D/M/Y: " << std::endl;
	cin >> date;
}

void datesheet::setsubject() {
	cout << "Enter the subject: " << std::endl;
	cin >> subject;
}

void datesheet::settime() {
	cout << "Enter the time in the format 11:30-12:30: " << std::endl;
	cin >> time;
}

void datesheet::display() {
	cout << "-------------------------------------------------" << std::endl;
	cout << "|" << std::setw(20) << std::left << subject << "|"
		<< std::setw(10) << std::left << date << "|"
		<< std::setw(15) << std::left << time << "|" << std::endl;
	cout << "-------------------------------------------------" << std::endl;
}

class mcqquiz : public quiz {
private:
	char option1[20];
	char option2[20];
	char option3[20];
	char option4[20];
	char ans;

public:
	char getans();
	void getdata();
	void display();
};

char mcqquiz::getans() {
	return ans;
}

void mcqquiz::getdata() {
	string section;
	string subject;
	int l;
	cout << "Enter the section for the quiz: " << endl;
	cin >> section;
	cout << "Enter the subject of the quiz: " << endl;
	cin >> subject;
	fstream fout("mcqquizseclist", ios::app);
	fout << section + subject << endl;
	fout.close();
	cin.ignore();
	cout << "How many MCQs do you want to enter? " << endl;
	cin >> l;
	cin.ignore(); // Ignore the newline character
	ofstream fout1(section + subject, ios::out | ios::binary | ios::app);
	for (int i = 0; i < l; i++) {
		cout << "Type down MCQ statement: " << endl;
		cin.getline(statement, 50);
		cout << "Enter option 1: " << endl;
		cin.getline(option1, 20);
		cout << "Enter option 2: " << endl;
		cin.getline(option2, 20);
		cout << "Enter option 3: " << endl;
		cin.getline(option3, 20);
		cout << "Enter option 4: " << endl;
		cin.getline(option4, 20);
		while (true) {
			try {
				cout << "Enter your answer: ";
				cin >> ans;
				if (ans != 'a' && ans != 'b' && ans != 'c' && ans != 'd') {
					throw runtime_error("Invalid answer, please try again.");
				}
				break;
			}
			catch (const exception& e) {
				cout << e.what() << endl;
			}
		}
		cin.ignore(); // Ignore the newline character
		fout1.write((char*)this, sizeof(mcqquiz));
	}
	fout1.close();
}



void mcqquiz::display() {
	cout << "MCQ Statement: " << statement << endl;
	cout << endl;
	cout << "Options:" << endl;
	cout << "   a. " << option1 << endl;
	cout << "   b. " << option2 << endl;
	cout << "   c. " << option3 << endl;
	cout << "   d. " << option4 << endl;
}

class person {
protected:
	string name;
	string password;
	string id;
	char email[20];
	string number;
	string address;

public:
	void setname();
	string getname();
	void setpassword();
	string getpassword();
	void setid();
	string getid();
	void setemail();
	string getemail();
	void setaddress();
	string getaddress();
	void setnumber();
	string getnumber();
	virtual void display()=0;
};

void person::setname() {
	cout << "Enter the name: ";
	getline(cin, name);
}

string person::getname() {
	return name;
}

void person::setpassword() {
	cout << "Enter the password: ";
	cin >> password;
	cin.ignore();
}

string person::getpassword() {
	return password;
}

void person::setid() {
	cout << "Enter the ID: ";
	cin >> id;
	cin.ignore();
}

string person::getid() {
	return id;
}

void person::setemail() {
	cout << "Enter the email: ";
	cin.getline(email,20);
}

string person::getemail() {
	return email;
}

void person::setaddress() {
	cout << "Enter the address: ";
	cin >> address;
	cin.ignore();
}

string person::getaddress() {
	return address;
}

void person::setnumber() {
	cout << "Enter the number: ";
	cin >> number;
	cin.ignore();
}

string person::getnumber() {
	return number;
}

class student :public person {
private:
	string name;
	string section;
	string department;
	int semester;
public:
	void setname();
	string getname();
	void setsection();
	string getsection();
	void setdepartment();
	string getdepartment();
	void setsemester();
	int getsemester();
	void givequizforone();
	void givequizforall();
	void checkmarks();
	void checkmarksone();
	void checkmarkass();
	void giveassignmentforall();
	void giveassignmentforone();
	void checkmarksassone();
	void checkattendance();
	void showdatesheet();
	void givemcqquiz();
	void display() override;
};

void student::setname() {
	cout << "Enter the name: ";
	getline(cin, name);
}

string student::getname() {
	return name;
}

void student::setsection() {
	cout << "Enter the section: ";
	getline(cin, section);
}

string student::getsection() {
	return section;
}

void student::setdepartment() {
	cout << "Enter the department: ";
	getline(cin, department);
}

string student::getdepartment() {
	return department;
}

void student::setsemester() {
	cout << "Enter the semester: ";
	cin >> semester;
	cin.ignore();
}

int student::getsemester() {
	return semester;
}

void student::givequizforone() {
	quiz a;
	ifstream file;
	string l, id;
	int c = 0;

a:
	cout << "Enter your ID: ";
	cin >> id;

	fstream fout("quizstulist", ios::in);
	while (!fout.eof()) {
		getline(fout, l);
		if (id == l) {
			c++;
			break;
		}
	}

	if (c == 0) {
		cout << "There is no quiz for you." << endl;
		goto a;
	}

	file.open(id, ios::in | ios::binary);
	file.read((char*)&a, sizeof(class quiz));

	while (!file.eof()) {
		a.display();
		file.read((char*)&a, sizeof(class quiz));
	}

	file.close();

	ofstream f;
	string n = id + "answer";
	answer ansss;

	cout << "Enter your answer: " << endl;
	cin.ignore();
	ansss.getanswer();

	f.open(n, ios::out | ios::app | ios::binary);
	f.write((char*)&ansss, sizeof(class answer));
	f.close();
}
void student::givequizforall() {
	quiz a;
	answer aa;
	ifstream file;
	int c = 0;
	string l;
	string sec, sub;

	cout << "Enter your section: ";
	cin >> sec;

	cout << "Enter the subject: ";
	cin >> sub;

	fstream fout("quizseclist", ios::in);

	while (!fout.eof()) {
		getline(fout, l);

		if (sec + sub == l) {
			c++;
		}
	}

	if (c == 0) {
		cout << "\nThere is no quiz for your section.\n";
	}

	if (c == 1) {
		int c1 = 0;

		aa.setid();

		ofstream op;
		ofstream fout1;

		op.open(sec + sub + "taken", ios::app);
		op.close();

		ifstream ifin;
		ifin.open(sec + sub + "taken", ios::in);

		while (!ifin.eof()) {
			getline(ifin, l);

			if (l == aa.getid()) {
				cout << "\nYou have already attempted the quiz.\n";
				c1++;
			}
		}

		if (c1 == 0) {
			fout1.open(sec + sub + "taken", ios::app);
			fout1 << aa.getid() << endl;;
			fout1.close();

			file.open(sec + sub, ios::in | ios::binary);
			if (file.is_open()) {
				file.read(a.statement, 49); // Read the statement directly into the statement data member
				a.display();
				file.close();
			}
			else {
				cout << "Error opening file." << endl;
			}

			cin.ignore();

			ofstream ff;
			string s = sec + sub + "answer";
			ff.open(s, ios::out | ios::app | ios::binary);

			cout << "\nBelow is your answer:\n";
			aa.getanswer();
			ff.write((char*)&aa, sizeof(class answer));
			ff.close();
		}
	}
}

// Function to check marks of a student in a particular section and subject
void student::checkmarks()
{
	ifstream file;
	marks m;
	int c = 0;
	string l;
	string sec, sub;

	// Ask for section and subject from user
a:
	cout << "Enter your section: " << endl;
	cin >> sec;
	cout << "Enter the subject: " << endl;
	cin >> sub;

	// Open file containing list of sections and subjects
	fstream fout("markseclist", ios::in);
	// Loop through the file and check if the section and subject match
	while (!fout.eof()) {
		getline(fout, l);
		if (sec + sub == l) {
			c++;
			break;
		}
	}

	// If section and subject not found in list, ask again
	if (c == 0) {
		cout << "Your marks have not been uploaded yet. Please try again." << endl;
		goto a;
	}

	// Open file containing marks for the given section and subject
	file.open("marks" + sec + sub, ios::in | ios::binary);
	if (!file) {
		cout << "The record does not exist." << endl;
	}
	else {
		int c = 0;
		string idd;

		// Ask for student ID and read marks from file
		cout << "Enter your ID: " << endl;
		cin >> idd;
		file.read((char*)&m, sizeof(class marks));

		// Loop through the file and display marks if student ID matches
		while (!file.eof()) {
			if (idd == m.getid()) {
				m.showmarks();
			}
			file.read((char*)&m, sizeof(class marks));
		}
	}

	file.close(); // Close the file
}

// Function to check marks of a student using their ID
void student::checkmarksone() {
	ifstream file;
	marks m;
	int c = 0;
	string l;
	string id;

	// Ask for student ID from user
a:
	cout << "Enter your ID: " << endl;
	cin >> id;

	// Open file containing list of student IDs
	fstream fout("markseclistone", ios::in);
	// Loop through the file and check if the student ID matches
	while (!fout.eof()) {
		getline(fout, l);
		if (id == l) {
			c++;
			break;
		}
	}

	// If student ID not found in list, ask again
	if (c == 0) {
		cout << "Your marks have not been uploaded yet. Please try again." << endl;
		goto a;
	}

	// Open file containing marks for the given student ID
	file.open("marks" + id, ios::in | ios::binary);
	if (!file) {
		cout << "The record does not exist." << endl;
	}
	else {
		int c = 0;
		// Read marks from file and display if student ID matches
		file.read((char*)&m, sizeof(class marks));
		while (!file.eof()) {
			if (id == m.getid()) {
				m.showmarks();
				file.read((char*)&m, sizeof(class marks));
				c++;
			}
		}
	}

	// If no marks found for the given student ID, display message
	if (c == 0) {
		cout << "Your result is not present." << endl;
	}

	file.close(); // Close the file
}
void student::checkmarkass() {
	ifstream file;
	marks m;
	int c = 0;
	string l;
	string sec, sub;
a:
	cout << "Enter your section:" << endl;
	cin >> sec;
	cout << "Enter your subject:" << endl;
	cin >> sub;
	string s = sec + sub;
	fstream fout("markassseclist", ios::in);
	while (!fout.eof()) {
		getline(fout, l);
		if (s == l) {
			c++;
			break;
		}
	}
	if (c == 0) {
		cout << "Your marks have not been uploaded yet." << endl;
		goto a;
	}
	file.open("marksass" + sub + sec, ios::in | ios::binary);
	if (!file) {
		cout << "The record does not exist." << endl;
	}
	else {
		int c = 0;
		string idd;
		string name;
		cout << "Enter your ID:" << endl;
		cin >> idd;
		file.read((char*)&m, sizeof(class marks));
		while (!file.eof()) {
			if (idd == m.getid()) {
				m.showmarks();
			}
			file.read((char*)&m, sizeof(class marks));
		}
	}
	file.close();
}
void student::giveassignmentforall() {
	string sec, subject;
	cout << "Enter your section: ";
	cin >> sec;
	cout << "Enter the subject of the assignment: ";
	cin >> subject;
	string section_subject = sec + subject;

	ifstream section_list_file("assseclist");
	string section_list_line;

	bool section_found = false;
	while (getline(section_list_file, section_list_line)) {
		if (section_list_line == section_subject) {
			section_found = true;
			break;
		}
	}
	section_list_file.close();

	if (!section_found) {
		cout << "There is no assignment for your section." << endl;
		return;
	}

	answer aa;
	aa.setid();

	ifstream taken_file(section_subject + "taken");
	string taken_id;

	bool already_taken = false;
	while (getline(taken_file, taken_id)) {
		if (taken_id == aa.getid()) {
			already_taken = true;
			break;
		}
	}
	taken_file.close();

	if (already_taken) {
		cout << "You have already attempted the assignment." << endl;
		return;
	}

	assignment as;
	ifstream assignment_file;
	assignment_file.open(section_subject + "assignment", ios::in | ios::binary);
	assignment_file.read((char*)&as, sizeof(as));
	as.display();
	assignment_file.close();

	cin.ignore();

	ofstream ff;
	ff.open(section_subject + "assighnmentanswers", ios::out | ios::app | ios::binary);
	cout << "Below, enter your answer:" << endl;
	aa.getanswer();
	ff.write((char*)&aa, sizeof(class answer));
	ff.close();

	ofstream taken_out(section_subject + "taken", ios::out | ios::app);
	taken_out << aa.getid() << endl;
	taken_out.close();

	cout << "Assignment completed successfully." << endl;
}
void student::giveassignmentforone() {
	assignment a;
	ifstream file;
	string l, id, sub;
	int c = 0;
a:
	cout << "Enter your ID: ";
	cin >> id;
	cout << "Enter the subject: ";
	cin >> sub;

	// Check if the user has already submitted the assignment
	ifstream given_file("assonegiven");
	while (getline(given_file, l)) {
		if (id + sub == l) {
			cout << "You have already submitted this assignment." << endl;
			given_file.close();
			return;
		}
	}
	given_file.close();

	fstream fout("assstulist", ios::in);
	while (!fout.eof()) {
		getline(fout, l);
		if (id + sub == l) {
			c++;
			break;
		}
	}
	fout.close();
	if (c == 0) {
		cout << "There is no assignment for you." << endl;
		goto a;
	}

	file.open(id + sub + "assignment", ios::in | ios::binary);
	file.read((char*)&a, sizeof(a));
	while (!file.eof()) {
		a.display();
		file.read((char*)&a, sizeof(class assignment));
	}
	file.close();

	ofstream f;
	string n = id + sub + "assanswer";
	answer ansss;
	cout << "Enter your answer: " << endl;
	cin.ignore();
	ansss.getanswer();
	f.open(n, ios::out | ios::app | ios::binary);
	f.write((char*)&ansss, sizeof(class answer));
	f.close();

	// Store the student id in the "assonegiven" file
	ofstream given_file_out("assonegiven", ios::out | ios::app);
	given_file_out << id + sub << endl;
	given_file_out.close();
}
void student::checkmarksassone() {
	ifstream file;
	marks m;
	int c = 0;
	string l;
	string id, sub;
a:
	cout << "Enter your ID: " << endl;
	cin >> id;
	cout << "Enter the subject: " << endl;
	cin >> sub;

	fstream fout("markassstuone", ios::in);
	while (!fout.eof()) {
		getline(fout, l);
		if (id + sub == l) {
			c++;
			break;
		}
	}
	fout.close();

	if (c == 0) {
		cout << "Your marks have not been uploaded yet." << endl;
		goto a;
	}

	file.open("marksassone" + id + sub, ios::in | ios::binary);
	if (!file) {
		cout << "The record does not exist." << endl;
	}
	else {
		int c = 0;
		file.read((char*)&m, sizeof(class marks));
		while (!file.eof()) {
			if (id == m.getid()) {
				m.showmarks();
				file.read((char*)&m, sizeof(class marks));
				c++;
			}
		}
	}
	file.close();

	if (c == 0) {
		cout << "Your result is not present." << endl;
	}
}
void student::checkattendance() {
	attendence p; // Create an instance of the "attendence" class
	string section;
	string subject;
	string l; // Declare a variable to store the student's ID
	cout << "Enter the section of class" << endl;
	cin >> section;
	cout << "Enter the subject" << endl;
	cin >> subject;
	cout << "Enter your ID" << endl;
	cin >> l;
	ifstream ifin; // Declare an input file stream
	ifin.open(section + subject + "attendencelist", ios::in, ios::binary); // Open the attendance list file for the specified section and subject
	ifin.read((char*)&p, sizeof(p)); // Read attendance data into the "attendence" instance
	while (!ifin.eof()) {
		if (l == p.getid()) { // Check if the student ID matches the current attendance record
			p.attendenceshow(); // Display the attendance data for the current record
		}
		ifin.read((char*)&p, sizeof(p)); // Read the next attendance record
	}
}
void student::showdatesheet() {
	datesheet d;
	string c;
	cout << "Enter the class:" << endl;
	cin >> c;

	ifstream checkfile;
	checkfile.open("datesheetmade");
	string classname;
	bool found = false;
	while (checkfile >> classname) {
		if (classname == c) {
			found = true;
			break;
		}
	}
	checkfile.close();

	if (!found) {
		cout << "Date sheet has not been made for this class." << endl;
		return;
	}

	ifstream fin;
	fin.open(c + "datesheet");
	fin.read((char*)&d, sizeof(d));
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(20) << left << "Subject" << "|"
		<< setw(10) << left << "Date" << "|"
		<< setw(15) << left << "Time" << "|"
		<< endl;
	while (!fin.eof()) {
		d.display();
		fin.read((char*)&d, sizeof(d));
	}
}
void student::givemcqquiz() {
	mcqquiz m;
	string section;
	string subject;
	string id;
	int c = 0;
	int c1 = 0;
	char a;
	cout << "Enter your section" << endl;
	cin >> section;
	cout << "Enter the subject you want to take quiz" << endl;
	cin >> subject;
	cout << "Enter your id" << endl;
	cin >> id;
	string l;

	// Check if the quiz section exists
	fstream fout("mcqquizseclist", ios::in);
	bool sectionFound = false;
	while (getline(fout, l)) {
		if (l == section + subject) {
			sectionFound = true;
			break;
		}
	}
	fout.close();
	if (!sectionFound) {
		cout << "There is no quiz for your section" << endl;
		return; // Exit the function
	}

	// Check if the student has already attempted the quiz
	ifstream ifin;
	ifin.open(section + subject + "mcqtaken", ios::in);
	while (getline(ifin, l)) {
		if (l == id) {
			cout << "You have already attempted the quiz" << endl;
			c1++;
			break;
		}
	}
	ifin.close();
	if (c1 > 0) {
		return; // Exit the function
	}

	// Take the quiz
	int num = 0;
	int total = 0;
	ofstream fout1;
	fout1.open(section + subject + "mcqtaken", ios::app);
	fout1 << id << endl;
	fout1.close();
	ifstream file;
	file.open(section + subject, ios::in | ios::binary);
	file.read((char*)&m, sizeof(m));
	while (file) { // Use the file object to check if there is more data to read
		m.display();
		while (true) {
			try {
				cout << "Enter your answer: ";
				cin >> a;
				if (a != 'a' && a != 'b' && a != 'c' && a != 'd') {
					throw runtime_error("Invalid answer, please try again.");
				}
				break;
			}
			catch (const exception& e) {
				cout << e.what() << endl;
			}
		}
		if (a == m.getans()) {
			num++;
		}
		total++;
		file.read((char*)&m, sizeof(m));
	}
	file.close();

	// Show the results
	cout << "You have answered " << num << " out of " << total << " questions correctly" << endl;
	double percentage = static_cast<double>(num) / total * 100;
	cout << "Your percentage is " << setprecision(2) << fixed << percentage << "%" << endl;
	fstream fout2(section + subject + "mcqresult", ios::app);
	fout2 << id << ":" << num << endl;
	fout2.close();
}
void student::display() {
	cout << "======================================" << endl;
	cout << "ID:         " << id << endl;
	cout << "Name:       " << name << endl;
	cout << "Email:      " << email << endl;
	cout << "Number:     " << number << endl;
	cout << "Address:    " << address << endl;
	cout << "Password:   " << password << endl;
	cout << "Department: " << department << endl;
	cout << "Section:    " << section << endl;
	cout << "Semester:   " << semester << endl;
	cout << "======================================" << endl;
}


class teacher : public person
{
protected:
	string department;
	string degree;
	string salary;
	int experience;
	int numresearch;
	vector<string> publications;

public:
	void setsalary();
	string getsalary();
	string getdepartment();
	void setdepartment();
	void makequizforsec();
	void makequizforone();
	void checkquizforall();
	void checkquizforone();
	void makeassignmentforall();
	void makeassignmentforone();
	void checkassignmentforall();
	void checkassone();
	void markattendance();
	void makemcqquiz();
	void showmcqresult();
	void display() ;
};


void teacher::setsalary()
{
	cout << "Enter the salary: " ;
	cin >> salary;
	cin.ignore();
}

string teacher::getsalary()
{
	return salary;
}

void teacher::setdepartment()
{
	cout << "Enter the department: " ;
	cin >> department;
	cin.ignore();
}

string teacher::getdepartment()
{
	return department;
}

void teacher::makequizforsec()
{
	quiz a;
	a.getdata();
}

void teacher::makequizforone()
{
	quiz f;
	f.getdataforone();
}

void teacher::checkquizforall()
{
	answer anss;
	marks m;
	string a, b;
	cout << "Enter the section of the quiz: " << endl;
	cin >> b;
	cout << "Enter the subject: " << endl;
	cin >> a;
	cin.ignore();
	string my = b + a + "answer";
	ifstream boom;
	boom.open(my, ios::in | ios::binary);
	string s = b + a + "checkedquiz";
	string checked_id;
	if (!boom.is_open()) {
		cout << "Error opening assignment answers file." << endl;
		return;
	}

	while (boom.read((char*)&anss, sizeof(answer))) {
		bool paper_checked = false;
		string current_id = anss.getid();

		// Check if the paper has already been checked
		ifstream checked_papers_file(s);
		while (getline(checked_papers_file, checked_id)) {
			if (checked_id == current_id) {
				paper_checked = true;
				break;
			}
		}
		checked_papers_file.close();

		if (!paper_checked) {
			anss.displayans();
			m.setid(anss.getid());
			m.getmarksdata();

			// Add the paper ID to the checked papers file
			ofstream checked_papers(s, ios::app);
			checked_papers << current_id << endl;

			// Ask the user if they want to check the next paper
			char choice;
			cout << "Do you want to check the next paper? (Y/N): ";
			cin >> choice;
			if (toupper(choice) == 'N') {
				break; // Exit the loop if the user doesn't want to check the next paper
			}
		}
	}

	boom.close();
}

void teacher::checkquizforone()
{
	answer anss;
	marks m1;
	string a, b;
	string roll;
	cout << "Enter the roll number of the student whose quiz is to be checked: " << endl;
	cin >> roll;
	cin.ignore();

	string m = roll + "answer";
	ifstream boom;
	boom.open(m, ios::in | ios::binary);
	boom.read((char*)&anss, sizeof(answer));
	while (!boom.eof()) {
		anss.displayans();
		boom.read((char*)&anss, sizeof(anss));
		m1.getmarksdataone();
	}
	boom.close();
}

void teacher::makeassignmentforall()
{
	assignment f;
	f.getdata();
}

void teacher::makeassignmentforone()
{
	assignment a;
	a.getdataforoneass();
}

void teacher::checkassignmentforall()
{
	answer anss;
	string a, b;
	marks m;
	cout << "Enter the section of the quiz: ";
	cin >> b;
	cin.ignore();
	cout << "Enter the subject of the assignment: ";
	cin >> a;
	string my = b + a + "assighnmentanswers";
	string s = b + a + "checkedpapers";
	string checked_id;

	ifstream boom(my, ios::in | ios::binary);
	if (!boom.is_open()) {
		cout << "Error opening assignment answers file." << endl;
		return;
	}

	while (boom.read((char*)&anss, sizeof(answer))) {
		bool paper_checked = false;
		string current_id = anss.getid();

		// Check if the paper has already been checked
		ifstream checked_papers_file(s);
		while (getline(checked_papers_file, checked_id)) {
			if (checked_id == current_id) {
				paper_checked = true;
				break;
			}
		}
		checked_papers_file.close();

		if (!paper_checked) {
			anss.displayans();
			m.setid(anss.getid());
			m.getmarkdataass();

			// Add the paper ID to the checked papers file
			ofstream checked_papers(s, ios::app);
			checked_papers << current_id << endl;

			// Ask the user if they want to check the next paper
			char choice;
			cout << "Do you want to check the next paper? (Y/N): ";
			cin >> choice;
			if (toupper(choice) == 'N') {
				break; // Exit the loop if the user doesn't want to check the next paper
			}
		}
	}

	boom.close();
}

void teacher::checkassone()
{
	answer anss;
	marks m1;
	string roll, sub;
	cout << "Enter the ID number of the student whose quiz is to be checked: " << endl;
	cin >> roll;
	cout << "Enter the subject: " << endl;
	cin >> sub;
	cin.ignore();

	string m = roll + sub + "assanswer";
	ifstream boom;
	boom.open(m, ios::in | ios::binary);
	boom.read((char*)&anss, sizeof(answer));
	while (!boom.eof()) {
		anss.displayans();
		boom.read((char*)&anss, sizeof(anss));
		m1.setid(anss.getid());
		m1.getmarksdataassone();
	}
	boom.close();

	// Store the student ID and subject in the "markassstuone" file
	ofstream mark_file("markassstuone", ios::out | ios::app);
	mark_file << roll + sub << endl;
	mark_file.close();
}

void teacher::markattendance()
{
	attendence p;
	string section;
	string subject;
	cout << "Enter the section of the class: " << endl;
	cin >> section;
	cout << "Enter the subject: " << endl;
	cin >> subject;
	ifstream ifin(section + subject + "attendencelist", ios::in);
	ofstream fout("temp.txt", ios::out);
	while (ifin.read((char*)&p, sizeof(p))) {
		p.attendenceshow();
		int l = p.getpresent();
		int k = p.gettotaldays();
		cout << "Press 1 if student is present\nPress 2 if student is absent: " << endl;
		int c;
		cin >> c;
		if (c == 1) {
			l++;
			p.setpresent(l);
		}
		k++;
		p.settotaldays(k);
		fout.write((char*)&p, sizeof(p));
	}
	fout.close();
	ifin.close();
	remove((section + subject + "attendencelist").c_str());
	rename("temp.txt", (section + subject + "attendencelist").c_str());
}

void teacher::makemcqquiz()
{
	mcqquiz m;
	m.getdata();
}

void teacher::showmcqresult()
{
	string section;
	string subject;
	cout << "Enter the section: " << endl;
	cin >> section;
	cout << "Enter the subject of the quiz: " << endl;
	cin >> subject;
	string l;
	fstream fin(section + subject + "mcqresult", ios::in);
	while (!fin.eof()) {
		getline(fin, l);
		cout << l << endl;
	}
}

void teacher::display()
{
	cout << "======================================" << endl;
	cout << "ID: " << id << endl;
	cout << "Address: " << address << endl;
	cout << "Email: " << email << endl;
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
	cout << "Password: " << password << endl;
	cout << "Department: " << department << endl;
	cout << "Salary: " << salary << endl;
	cout << "======================================" << endl;
}
class administrator {
public:
	bool login();
	void readfromfile();
	void addtofilestudent();
	void searchstudentbyid(string idd);
	void removestudentbyidandname(string idd, string name);
	void resetdatast(string idd);
	void addtofileteacher();
	void searchteacherbyid(string idd);
	void removeteacherbyidandname(string idd, string namee);
	void resetdatateach(string idd);
	void makeattendencelist();
	void writedatesheet();
};
bool administrator::login()
{
	bool thebool = false;
	//vector<string>adminpass={"admin123","admin","adminfaiq","adminmoiz"};
	string adminpass[] = { "admin123","admin" };
aap:
	cout << "enter your password: " << endl;
	string pass;
	cin >> pass;
	cin.ignore();
	int i = 0;
	for (i; i < 2; i++)
	{
		if (pass == adminpass[i])
		{
			thebool = true;
			cout << "..........WELCOME..........." << endl;
			return true;
		}
	}
	if (!thebool)
	{
		cout << "cannot login. Please try again." << endl;
		goto aap;
	}
}


void administrator::readfromfile()
{
	cout << "Press 1 to see student records." << endl;
	cout << "Press 2 to see teacher records." << endl;
	int c;
	cin >> c;
	person* p1;
	if (c == 1) {
		cout << "Reading from the file." << endl;
		student a;
		p1 = &a;
		ifstream fin;
		fin.open("studentsdata.bin", ios::in | ios::binary);
		fin.read((char*)&a, sizeof(a));
		while (!fin.eof())
		{
			p1->display();
			fin.read((char*)&a, sizeof(a));
		}
		fin.close();
	}
	else if (c == 2) {
		cout << "Reading from the file." << endl;
		teacher b;
		ifstream finn;
		finn.open("teachersdata.bin", ios::in | ios::binary);
		finn.read((char*)&b, sizeof(teacher));
		while (!finn.eof())
		{
			b.display();
			finn.read((char*)&b, sizeof(teacher));
		}
		finn.close();
	}
}
void administrator::addtofilestudent()
{
	student a;
	a.setid();
	a.setaddress();
	a.setemail();
	a.setname();
	a.setnumber();
	a.setpassword();
	a.setsection();
	a.setdepartment();
	a.setsemester();
	ofstream fout;
	fout.open("studentsdata.bin", ios::app | ios::binary);
	fout.write((char*)&a, sizeof(a));
	fout.close();
}
void administrator::searchstudentbyid(string idd)
{
	int count = 0;

	ifstream file;
	file.open("studentsdata.bin", ios::in | ios::binary);
	if (!file)
	{
		cout << "File not found." << endl;
	}
	else
	{
		student a;
		person* p1 = &a;

		while (file.read((char*)&a, sizeof(student)))
		{
			if (idd == a.getid())
			{
				p1->display();
				count++;
			}
		}

		file.close();

		if (count == 0)
			cout << "Not found." << endl;
	}
}


void administrator::removestudentbyidandname(string idd, string name)
{
	int counter = 0;
	student a;
	ifstream fin;
	ofstream fout;
	fin.open("studentsdata.bin", ios::in | ios::binary);
	fout.open("tempstudent.bin", ios::out | ios::binary);
	if (!fin)
	{
		cout << "No record exists." << endl;
	}
	else
	{
		while (fin.read((char*)&a, sizeof(a)))
		{
			if (a.getid() == idd && a.getname() == name)
			{
				counter++;
			}
			else
			{
				fout.write((char*)&a, sizeof(a));
			}
		}
		if (counter == 0)
		{
			cout << "No record found." << endl;
		}
		else
		{
			cout << "Removed " << counter << " records." << endl;
		}
		fin.close();
		fout.close();
		remove("studentsdata.bin");
		rename("tempstudent.bin", "studentsdata.bin");
	}
}

void administrator::resetdatast(string idd)
{
	student a;
	fstream file;
	file.open("studentsdata.bin", ios::in | ios::out | ios::binary);
	if (!file)
	{
		cout << "File does not exist." << endl;
	}
	else
	{
		bool recordFound = false;
		while (file.read((char*)&a, sizeof(a)))
		{
			if (a.getid() == idd)
			{
				recordFound = true;
				a.setid();
				a.setaddress();
				a.setemail();
				a.setname();
				a.setnumber();
				a.setpassword();
				a.setsection();
				a.setdepartment();
				a.setsemester();
				file.seekp(int(file.tellg()) - sizeof(a));
				file.write((char*)&a, sizeof(a));
				break; // Exit the loop after updating the record
			}
		}

		if (recordFound)
		{
			cout << "Record updated successfully." << endl;
		}
		else
		{
			cout << "Record not found." << endl;
		}
	}

	file.close();
}

void administrator::addtofileteacher()
{
	teacher a;
	a.setid();
	a.setaddress();
	a.setemail();
	a.setname();
	a.setnumber();
	a.setpassword();
	a.setdepartment();
	a.setsalary();
	//a.setclasses();
	ofstream fout;
	fout.open("teachersdata.bin", ios::app | ios::binary);
	fout.write((char*)&a, sizeof(teacher));
	fout.close();
}

void administrator::searchteacherbyid(string idd)
{
	teacher a;
	ifstream file;
	person* p1 = &a;
	file.open("teachersdata.bin", ios::in | ios::binary);
	if (!file)
	{
		cout << "File not found." << endl;
	}
	else
	{
		file.read((char*)&a, sizeof(teacher));
		while (!file.eof())
		{
			if (idd == a.getid())
			{
				p1->display();
			}
			file.read((char*)&a, sizeof(teacher));
		}
	}
}

void administrator::removeteacherbyidandname(string idd, string namee)
{
	teacher a;
	ifstream fin;
	ofstream fout;
	fin.open("teachersdata.bin", ios::in | ios::binary);
	if (!fin)
	{
		cout << "No record exists." << endl;
		return;
	}
	fout.open("tempteacher.bin", ios::out | ios::binary);
	fin.read((char*)&a, sizeof(teacher));
	while (!fin.eof())
	{
		if (a.getid() == idd && a.getname() == namee)
		{
			cout << "Teacher removed: " << a.getname() << endl;
		}
		else
		{
			fout.write((char*)&a, sizeof(teacher));
		}
		fin.read((char*)&a, sizeof(teacher));
	}
	fin.close();
	fout.close();
	remove("teachersdata.bin");
	rename("tempteacher.bin", "teachersdata.bin");
}

void administrator::resetdatateach(string idd)
{
	teacher t;
	fstream file;
	file.open("teachersdata.bin", ios::in | ios::out | ios::binary);
	file.seekg(0);
	if (!file)
	{
		cout << "File does not exist." << endl;
	}
	else
	{
		bool found = false;
		while (file.read((char*)&t, sizeof(teacher)))
		{
			if (t.getid() == idd)
			{
				found = true;
				t.setid();
				t.setaddress();
				t.setemail();
				t.setname();
				t.setnumber();
				t.setpassword();
				t.setdepartment();
				t.setsalary();
				file.seekp(int(file.tellg()) - sizeof(teacher));
				file.write((char*)&t, sizeof(teacher));
				break;
			}
		}

		if (!found)
		{
			cout << "Teacher with ID " << idd << " not found." << endl;
		}
	}
	file.close();
}

void administrator::makeattendencelist() {
	attendence p;
	string section;
	string subject;
	cout << "Enter the section of class:" << endl;
	cin >> section;
	cout << "Enter the subject:" << endl;
	cin >> subject;
	int l;
	cout << "Enter the number of students you want to enter:" << endl;
	cin >> l;
	ofstream fout;
	fout.open(section + subject + "attendencelist", ios::app, ios::binary);
	for (int i = 0; i < l; i++) {
		p.setname();
		p.setid();
		p.setpresent(0);
		p.settotaldays(0);
		fout.write((char*)&p, sizeof(p));
	}
}

void administrator::writedatesheet() {
	string c;
	cout << "Enter the class:" << endl;
	cin >> c;

	// Check if the class record already exists
	ifstream checkFile("datesheetmade");
	string line;
	bool classExists = false;
	while (getline(checkFile, line)) {
		if (line == c) {
			classExists = true;
			break;
		}
	}
	checkFile.close();

	// If the class record exists, ask if the user wants to overwrite it
	if (classExists) {
		char choice;
		cout << "A date sheet for this class already exists. Do you want to overwrite it? (Y/N)" << endl;
		cin >> choice;
		if (choice != 'Y' && choice != 'y') {
			return;
		}
	}

	// Open the file to write the date sheet for the class
	ofstream fout;
	fout.open(c + "datesheet");

	int l;
	cout << "How many subjects you want to enter?" << endl;
	cin >> l;

	for (int i = 0; i < l; i++) {
		datesheet d;
		d.setsubject();
		d.setdate();
		d.settime();
		fout.write((char*)&d, sizeof(d));
	}

	// Add the class name to the list of date sheets made
	ofstream classList("datesheetmade", ios::app);
	classList << c << endl;
	classList.close();

	cout << "Date sheet created successfully." << endl;
}

int main() {
	administrator a;
go1:
	system("CLS");
	cout << setw(80) << setfill('=') << "" << endl;
	setColor(WHITE, BLUE);
	cout << setw(39) << setfill(' ') << "STUDENT MANAGEMENT SYSTEM" << setw(40) << "" << endl;
	setColor(WHITE, BLACK);
	cout << setw(80) << setfill('=') << "" << endl;
	cout << endl;
	cout << "1 : Administrator login" << endl;
	cout << "2 : Student login" << endl;
	cout << "3 : Teacher login" << endl;
	cout << endl;
	int nn;
	cout << "Enter: ";
	cin >> nn;
	if (nn == 1)
	{
		bool bb;
		bb = a.login();
		if (bb)
		{
		go2:
			system("CLS");
			cout << setw(80) << setfill('=') << "" << endl;
			setColor(WHITE, BLUE);
			cout << setw(39) << setfill(' ') << "WELCOME TO ADMIN LOBBY" << setw(40) << "" << endl;
			setColor(WHITE, BLACK);
			cout << setw(80) << setfill('=') << "" << endl;
			cout << endl;
			cout << "1 Search student record with ID" << endl;
			cout << "2 Search teacher record with ID" << endl;
			cout << "3 Remove student record with ID and name" << endl;
			cout << "4 Remove teacher record with ID and name" << endl;
			cout << "5 Reset student record" << endl;
			cout << "6 Reset teacher record" << endl;
			cout << "7 Access whole record" << endl;
			cout << "8 Add a student to record" << endl;
			cout << "9 Add a teacher to record" << endl;
			cout << "10 Make attendance list" << endl;
			cout << "11 Press to make datesheet" << endl;
			cout << "12 Press to go to main" << endl;
			cout << endl;
			int nnn;
			cout << "Enter: ";
			cin >> nnn;
			cin.ignore();
			if (nnn == 1)
			{
				string m;
				cout << "Enter student ID: ";
				cin >> m;
				cin.ignore();
				a.searchstudentbyid(m);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;

			}
			else if (nnn == 2)
			{
				string m;
				cout << "Enter teacher ID: ";
				cin >> m;
				cin.ignore();
				a.searchteacherbyid(m);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;
			}
			else if (nnn == 3)
			{
				string m;
				string n;
				cout << "Enter student ID: ";
				cin >> m;
				cin.ignore();
				cout << "Enter student name: ";
				getline(cin, n);
				a.removestudentbyidandname(m, n);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 4)
			{
				string m;
				string n;
				cout << "Enter teacher ID: ";
				cin >> m;
				cin.ignore();
				cout << "Enter teacher name: ";
				getline(cin, n);
				a.removeteacherbyidandname(m, n);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;
			}
			else if (nnn == 5)
			{
				string m;
				cout << "Enter ID: ";
				cin >> m;
				a.resetdatast(m);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;
			}
			else if (nnn == 6)
			{
				string m;
				cout << "Enter ID: ";
				cin >> m;
				a.resetdatateach(m);
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				goto go2;
			}
			else if (nnn == 7)
			{
				a.readfromfile();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 8)
			{
				a.addtofilestudent();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 9)
			{
				a.addtofileteacher();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 10)
			{
				a.makeattendencelist();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 11)
			{
				a.writedatesheet();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go2;
			}
			else if (nnn == 12)
			{
				goto go1;
			}

		}
	}
	else if (nn == 2)
	{
		student s;
		int l = 1;
		if (l == 1)
		{
		go3:
			system("CLS");
			cout << setw(80) << setfill('=') << "" << endl;
			setColor(WHITE, BLUE);
			cout << setw(39) << setfill(' ') << "WELCOME TO STUDENT LOBBY" << setw(40) << "" << endl;
			setColor(WHITE, BLACK);
			cout << setw(80) << setfill('=') << "" << endl;
			cout << endl;
			cout << "1 Give assignment of section" << endl;
			cout << "2 View date sheet" << endl;
			cout << "3 Give quiz for all" << endl;
			cout << "4 Give quiz for one" << endl;
			cout << "5 Check attendance" << endl;
			cout << "6 Check marks of quiz" << endl;
			cout << "7 Check marks of assignment" << endl;
			cout << "8 Display information" << endl;
			cout << "9 To give MCQ test" << endl;
			cout << "10 Go to main menu" << endl;
			int h;
			cout << endl;
			cout << "Enter choice: ";
			cin >> h;
			cin.ignore();
			if (h == 1)
			{
				s.giveassignmentforall();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 2)
			{
				s.showdatesheet();
				cout << endl;
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 3)
			{
				s.givequizforall();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 4)
			{
				s.givequizforone();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 5)
			{
				s.checkattendance();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 6)
			{
				int c;
				setColor(WHITE, MAGENTA);
				cout << "Press 1 to check marks for collective quiz or 2 for individual quiz: ";
				setColor(WHITE, BLACK);
				cin >> c;
				if (c == 1) {
					s.checkmarks();
				}
				else if (c == 2) {
					s.checkmarksone();
				}
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 7)
			{
				int c;
				setColor(WHITE, MAGENTA);
				cout << "Press 1 to check marks for collective assignment or 2 for individual assignment: ";
				setColor(WHITE, BLACK);
				cin >> c;
				if (c == 1) {
					s.checkmarkass();
				}
				else if (c == 2) {
					s.checkmarksassone();
				}
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 8)
			{
				//s.displayinfo();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 9)
			{
				s.givemcqquiz();
				setColor(WHITE, BLUE);
				cout << "Press any key to continue" << endl;
				setColor(WHITE, BLACK);
				getchar();
				getchar();
				goto go3;
			}
			else if (h == 10)
			{
				goto go1;
			}
			else
			{
				cout << "Invalid input, please try again" << endl;
				goto go3;
			}
		}
	}
	else if (nn == 3)
	{
		teacher t;
		int l = 1;
		if (l == 1)
		{
		go4:
			system("CLS");
			cout << setw(80) << setfill('=') << "" << endl;
			setColor(WHITE, BLUE);
			cout << setw(39) << setfill(' ') << "WELCOME TO TEACHER LOBBY" << setw(40) << "" << endl;
			setColor(WHITE, BLACK);
			cout << setw(80) << setfill('=') << "" << endl;
			cout << endl;
			cout << "1 Check assignment of section" << endl;
			cout << "2 Check assignment for one" << endl;
			cout << "3 Check quiz for section" << endl;
			cout << "4 Check quiz for one" << endl;
			cout << "5 Display information from record" << endl;
			cout << "6 Student record display" << endl;
			cout << "7 Mark attendance" << endl;
			cout << "8 Make assignment for all" << endl;
			cout << "9 Make assignment for one" << endl;
			cout << "10 Make quiz for section" << endl;
			cout << "11 Make quiz for one" << endl;
			cout << "12 Make MCQ quiz" << endl;
			cout << "13 Go to main menu" << endl;
			int bu;
			cout << endl;
			cout << "Enter option: ";
			cin >> bu;
			cin.ignore();
			if (bu == 1)
			{
				t.checkassignmentforall();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 2)
			{
				t.checkassone();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 3)
			{
				t.checkquizforall();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 4)
			{
				t.checkquizforone();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 5)
			{
				//t.displayinfo();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 6)
			{
				//t.sturecord();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 7)
			{
				t.markattendance();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 8)
			{
				t.makeassignmentforall();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 9)
			{
				t.makeassignmentforone();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 10)
			{
				t.makequizforsec();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 11)
			{
				t.makequizforone();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 12)
			{
				t.makemcqquiz();
				cout << "Press any key to continue" << endl;
				getchar();
				getchar();
				goto go4;
			}
			else if (bu == 13)
			{
				goto go1;
			}
		}
	}
	return 0;
}



