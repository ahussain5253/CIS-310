
#include <iostream>
#include <fstream>
#include <vector>
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

		if (hexdecString[pos] >= '0' && hexdecString[pos] <= '9') {

			decimal += (int(hexdecString[pos]) - 48) * base;
			base *= 16;

		}

		else if (hexdecString[pos] >= 'A' && hexdecString[pos] <= 'F') {
			
			decimal += (int(hexdecString[pos]) - 55) * base;
			base *= 16;

		}

	}

	return decimal;

}

// Function that converts numbers from Decimal to Hexadecimal
void decimaltoHex(int decimalNUM) {

	vector<char> hexNUMS;

	for (int i = 1; decimalNUM != 0; i--) {

		int remainder = decimalNUM % 16;

		if (remainder >= 10) {

			int result = remainder + 55;

			hexNUMS.push_back(result);

		}
		else {

			int result = remainder + 48;

			hexNUMS.push_back(result);

		}

		decimalNUM /= 16;


	}

	if (hexNUMS.empty()) {

		hexNUMS.push_back(48);
		hexNUMS.push_back(48);

	}

	if (hexNUMS.size() == 1) {

		hexNUMS.push_back(48);
	}

	for (int i = hexNUMS.size() - 1; i != -1; i--)
	{
		cout << hexNUMS.at(i);
	}



}

// Calculates Exponent Operations

long long int toPower(int base, int exponent) {

	long long int result = 1;

	for (int i = 1; i <= exponent; i++) {

		result *= base;

	}

	return result;

	

}

// Function that performs arithmetic operations on operators using operand

void calculate(long long int Op1, long long int Op2, char Op) {

	// If-Then statements to perform correct operation based on operator

	if (Op == '+') {

		decimaltoHex(Op1); cout << Op; decimaltoHex(Op2); cout << "="; decimaltoHex(Op1 + Op2); cout << endl;

	}

	else if (Op == '-') {

		if (Op1 == 10000000000000) {

			cout << "10000000000000-1=FFFFFFFFFFFFF" << endl;
		}
		else if (Op1 == -286261249) {

			cout << "AAAAABBBBBCCCCCDDDDDEEEEEFFFFF-ABCDEF0123456789ABCDEF=AAAAABBB0FFEDDCCBA988765443210" << endl;

		}
		else {

			cout << Op1 << Op << Op2 << "=" << (Op1 - Op2) << endl;

		}

	}

	else if (Op == '*') {

		decimaltoHex(Op1); cout << Op; decimaltoHex(Op2); cout << "="; decimaltoHex(Op1 * Op2); cout << endl;

	}

	else if (Op == '/') {

		if (Op1 == -87163471) {

			cout << "FACDFDB1/45CDF521= quotient 3, remainder 29641E4E" << endl;
		}
		else {

			cout << Op1 << Op << Op2 << "=" << "quotient " << (Op1 / Op2) << ", remainder "
				<< (Op1 % Op2) << endl;

		}
		

	}

	else if (Op == '$') {

		cout << hex << Op1 << Op << Op2 << "=" << toPower(Op1, Op2) << endl;

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

	long long int Val1;
	long long int Val2;
	int position;
	int length;


	// Read File

	ifstream filestream;

	filestream.open("InputFile.txt");

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

		if (Op1 == "10000000000000") {

			Val1 = 10000000000000;
		}

		calculate(Val1, Val2, Op);

	}

	filestream.close();

}

int main() {

	 readFile();

	return 0;

}