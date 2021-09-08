#include <iostream>

using namespace std;

void decimalToBinary(int decimalNUM) {

	int binary[8];

	for (int i = 0; i < 8; i++) {

		binary[i] = 0;

	}

	int result = (decimalNUM / 2) + 0.5;
	int remainder = decimalNUM % 2;

	binary[7] = remainder;

	if (remainder != 0) {

		result = result / 2;

		remainder = result % 2;

		binary[6] = remainder;
	}

	if (remainder != 0) {

		result = result / 2;

		remainder = result % 2;

		binary[5] = remainder;
	}

	if (remainder != 0) {

		result = result / 2;

		remainder = result % 2;

		binary[4] = remainder;
	}

	if (remainder != 0) {

		result = result / 2;

		remainder = result % 2;

		binary[3] = remainder;
	}

	if (remainder != 0) {

		result = result / 2;

		remainder = result % 2;

		binary[2] = remainder;
	}

	if (remainder != 0) {

		result = result / 2;

		remainder = result % 2;

		binary[1] = remainder;
	}

	if (remainder != 0) {

		result = result / 2;

		remainder = result % 2;

		binary[0] = remainder;
	}

	for (int i = 0; i < 8; i++) {

		cout << binary[i];

	}

}

int main() {

	decimalToBinary(125);
	




	return 0;
}