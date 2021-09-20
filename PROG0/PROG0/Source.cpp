#include <iostream>
#include <array>
#include <vector>
#include <string>

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

	string decimal = to_string(decimalNUM);

	if (decimal.size() == 2) {

		cout << "0000 ";

	}

	if (decimal.size() == 1) {

		cout << "0000 0000 ";

	}

	for (int i = 0; i < decimal.size(); i++) {

		int BCD[4];

		for (int i = 0; i < 4; i++) {

			BCD[i] = 0;

		}

		int decimalNUM = decimal.at(i) - 48;

		for (int i = 3; decimalNUM != 0; i--) {

			int remainder = decimalNUM % 2;

			BCD[i] = remainder;

			decimalNUM /= 2;

		}

		for (int i = 0; i < 4; i++) {

			cout << BCD[i];

		}

		cout << " ";

	}
}

int main() {

	
	cout << "Decimal" << "    " << "Binary" << "      " << "HexDecimal" << "          " << "BCD" << endl << endl;

	for (int i = 0; i <= 255; i++) {

		cout << i << "         "; decimalToBinary(i);
		cout << "         "; decimaltoHex(i);
		cout << "         "; decimaltoBCD(i);
		cout << endl;

	}
	
	return 0;
}