#include <iostream>
#include <array>

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

	char hexNUMS[50];

	for (int i = 49; decimalNUM != 0; i--) {

		int remainder = decimalNUM % 16;

		if (remainder >= 10) {

			remainder + 55;

			hexNUMS[i] = remainder;

		}
		else {

			remainder + 48;

			hexNUMS[i] = remainder;

		}


	}

	for (int i = 0; i < 50; i++) {

		cout << hexNUMS[49];

	}



}

int main() {

	
/*
	for (int i = 0; i <= 255; i++) {

		cout << i << "      "; decimalToBinary(i); 
		cout << endl;

	}
	
	*/

	decimaltoHex(48);

	return 0;
}