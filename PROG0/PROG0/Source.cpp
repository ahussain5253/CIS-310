#include <iostream>
#include <array>
#include <vector>

using namespace std;

void decimalToBinary(int decimalNUM) {

	int binary[8];

	for (int i = 0; i < 8; i++) {

		binary[i] = 0;

	}

	for (int i = 7; decimalNUM != 0; i--) {

		binary[i] = decimalNUM % 2;

		decimalNUM /= 2;

	}


	for (int i = 0; i < 8; i++) {

		cout << binary[i];

	}

}

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

void decimaltoBCD(int decimalNUM) {

	int hundereds = decimalNUM / 100;

	cout << hundereds;
}

int main() {

	/*
	cout << "Decimal" << "    " << "Binary" << "      " << "HexDecimal" << endl << endl;

	for (int i = 0; i <= 255; i++) {

		cout << i << "         "; decimalToBinary(i); 
		cout << "         "; decimaltoHex(i);
		cout << endl;

	}
	*/

	decimaltoBCD(255);

	return 0;
}