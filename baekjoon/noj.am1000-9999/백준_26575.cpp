#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	double dC, fA, fP;
	cin >> T;
	while (T--) {
		cin >> dC >> fA >> fP;
		printf("$%.2f\n", dC * fA * fP);
	}
}
