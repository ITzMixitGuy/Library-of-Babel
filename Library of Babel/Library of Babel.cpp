#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
using namespace std;
int field1, field2, RAMP;
bool is_error = TRUE;
int not_an_input;
char r;
char ch;
int code;
int n=1;
bool print1 = 1;
#define DIV 1024
#define WIDTH 7
class Library {
private:
	int NoB;
	int NoC;
	int attemps;
	string q;
	string k;
	int l;
	string seachingfor;
	vector<string> books;


public:
	void showBooks() {
		while (true) {
			system("cls");
			cout << books[n] << endl <<"("<<n<<")";
			ch = _getch(); 

			if (ch == 'r') {
				FillUp(); 
				n = 1; 
			}

			
			if (ch == 'k' && n > 1) {
				n--; 
			}
			else if (ch == 'l' && (n < books.size() - 1)) {
				n++; 
			}
		}
	}

	void getFields(int numofb, int numofc) {
		NoB = numofb;
		NoC = numofc;
		books.resize(NoB + 1);
	}

	void FillUp() {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 26);
		for (int i = 1; i <= NoB; i++) {
			for (int n = 1; n <= NoC; n++) {
				l = dis(gen);
				if (l < 23) {
					k = 'a' + l;
					q = q + k;
				}
				else {
					switch (l)
					{
					case 23: {
						q = q + ' ';
						break;
					}
					case 24: {
						q = q + ',';
						break;
					}
					case 25: {
						q = q + '.';
						break;
					}
					}

				}
			}
			books[i] = q;
			q = "";
		}
	}

};

int main() {
	system("chcp 1251>nul");
	Library test;



	///////////////
	GOTOWARNING:///
	///////////////



	is_error = 1;
	while (is_error){
		is_error = 0;
		try {
			cout << "Enter the available amount of free RAM (%):";
			cin >> RAMP;
			cout << "Enter the number of characters in the book:";
			cin >> field1;
			cout << "Enter the number of books in the library:";
			cin >> field2;
			if (RAMP > 100) {
				throw("Allowed RAM is greater than the existing one!");
			}
		}
		catch (...) {
			cout << "An error has occurred! Possible reasons : The entered value is not int, the amount of allowed memory is greater than the existing one."<<endl;
			is_error = 1;
		}
	}

	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);

	if ((memInfo.ullAvailPhys/100)*RAMP <= (field1 * field2)) {
			not_an_input = 1;
			cout << "Warning: The entered values ​​will take up more memory than the entered value. This may cause the device to slow down while the program is running.Are you sure you want to continue (y/n) ?" << endl;
			while (not_an_input) {
				cin >> r;

				if (r == 'y') {
					not_an_input = 0;
				}

				if (r == 'n') {
					goto GOTOWARNING;
				}
			}
		}
	
	test.getFields(field2, field1);
	test.FillUp();
	test.showBooks();
	system("pause>nul");
	return 1;
}