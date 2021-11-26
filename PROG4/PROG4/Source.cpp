
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function that converts numbers from Hexadecimal to Decimal

int hexToDec(string hexdecString) {

	int length = hexdecString.length();
	int base = 1;
	int decimal = 0;
	int pos;

	// Loop that obtains characters from string

	for (pos = length - 1; pos >= 0; pos--)	{

		if (hexdecString.at(pos) >= '0' && hexdecString.at(pos) <= '9') {

			decimal += (hexdecString.at(pos) - 48) * base;
			base = base * 16;

		}

		else if (hexdecString.at(pos) >= 'A' && hexdecString.at(pos) <= 'F') {
			
			decimal += (hexdecString[pos] - 55) * base;
			base = base * 16;

		}

	}

	return decimal;

}

// Function that performs arithmetic operations on operators using operand

void calculate(int Op1, int Op2, char Op) {

	// If-Then statements to perform correct operation based on operator

	if (Op == '+') {

		cout << Op1 << Op << Op2 << "=" << (Op1 + Op2) << endl;

	}

	else if (Op == '-') {

		cout << Op1 << Op << Op2 << "=" << (Op1 - Op2) << endl;
	}

	else if (Op == '*') {

		cout << Op1 << Op << Op2 << "=" << (Op1 * Op2) << endl;
	}

	else if (Op == '/') {

		cout << Op1 << Op << Op2 << "=" << "quotient " << (Op1 / Op2) << ", remainder " << (Op1 % Op2) << endl;
	}

	else if (Op == '$') {

		cout << Op1 << Op << Op2 << "=" << pow(Op1, Op2) << endl;
	}

	else {

		cout << "\n Invalid Operator";
	}

}

// create a function to read file

void readFile() {

	string Op1;
	string Op2;
	string data;

	char Op;

	int Val1;
	int Val2;
	int position;
	int length;


	// Read File

	ifstream filestream;

	filestream.open("HexdecArithmetic.txt");

	if (!filestream) {

		cout << "\n ERROR !!";

		exit(0);

	}

	while (!filestream.eof()) {

		filestream >> data;

		length = data.length();

		// Find Operator using for loop

		for (position = 0; position < length; position++) {

			if (data.at(position) == '+' || data.at(position) == '-' || data.at(position) == '*' || data.at(position) == '/' || data.at(position) == '$')

				// Break loop if an operator is found

				break;
		}

		Op = data.at(position);
		Op1 = data.substr(0, position);
		Op2 = data.substr(position + 1, (data.length() - Op1.length() - 2));

		Val1 = hexToDec(Op1);
		Val2 = hexToDec(Op2);

		calculate(Val1, Val2, Op);

	}

	filestream.close();

}

int main() {

	readFile();

	return 0;

}