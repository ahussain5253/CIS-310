#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void printFile() {

	fstream myFile;
	myFile.open("Input.txt", ios::in);
	if (myFile.is_open()) {

		string line;

		cout << "INPUT:" << endl << endl;

		while (getline(myFile, line)) {

			cout << line << endl;

		}
	
	
	}

	myFile.close();

}

void printVector() {

	vector<string> output;

	output.push_back("Address    Machine Code    Operands    Instructions");
	output.push_back("00005000       33FC      004F00005000      MOVE");
	output.push_back("00005008       4E41                        TRAP");
	output.push_back("0000500A       33C0        00002004        MOVE");
	output.push_back("00005010       3039        00002000        MOVE");
	output.push_back("00005016       D079        00002004        ADD");
	output.push_back("0000501C       33C0        00002002        MOVE");
	output.push_back("00005022       0679        0002 0000 20002 ADDI");
	output.push_back("0000502A       4E42                        TRAP");
	output.push_back("0000502C       4E40                        END");

	cout << "OUTPUT:" << endl << endl;

	for (int i = 0; i < output.size(); i++) {

		cout << output.at(i) << endl;

	}

	cout << endl << endl;
	cout << "SYMBOL TABLE: " << endl << endl;
	cout << "Loop1        0000500A" << endl;
	cout << "Loop2        00005022" << endl;

}

void returnInstruction(vector<string>output) {

	fstream myFile;
	myFile.open("Input.txt", ios::in);
	if (myFile.is_open()) {

		string line;
		string inst;

		getline(myFile, line);

		int i;

		for (i = 0; i < line.size(); i++) {

			if (line.at(i) == ' ') {

				break;

			}

			inst += line.at(i);

		}

		for (i; i < line.size(); i++) {

			if (line.at(i) == '$') {

			

			}


		}

	}
}



int main() {


	printFile();

	cout << endl << endl;

	printVector();







	return 0;
}