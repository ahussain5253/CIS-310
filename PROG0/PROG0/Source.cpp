#include <iostream>

using namespace std;

int decimalToBinary(int decimalNum) {

	int binaryNum = decimalNum % 2;

	return binaryNum;

}

int main() {


	for (int i = 0; i < 255; i++) {

		cout << decimalToBinary(i) << endl;

	}
	




	return 0;
}