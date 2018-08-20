#include <iostream>
#include "BigNumber.h"
using namespace std;

int main() {
	BigNumber n(999999999);
	cout << n << endl;
	for (int i = 0; i < 500; i++) {
		n *=BigNumber(999999999);
		cout << n << endl;
	}
}