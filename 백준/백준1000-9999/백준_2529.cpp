#include <iostream>
using namespace std;

int n, nMax = -1, nMin = 10;
int arr[10], arrMax[10], arrMin[10], check[10];
char a[9];

void insert(int arrTo[]) {
	for (int i = 0; i <= n; i++)
		arrTo[i] = arr[i];
}

void print(int arrPrint[]){
	for(int i = 0; i <= n; i++)
		cout << arrPrint[i];
}
void f(int prev, int idx, int first_num) {
	if (idx-1 == n) {
		if (first_num < nMin){
			nMin = first_num;
			insert(arrMin);
		}
		if (first_num >= nMax){
			nMax = first_num;
			insert(arrMax);
		}
	}
	else
		for (int i = 0; i <= 9; i++) {
			if ((!idx || (a[idx - 1] == '<' && prev < i) || (a[idx - 1] == '>' && prev > i)) && !check[i]) {
				arr[idx] = i; check[i] = 1;
				f(i, idx + 1, !idx ? i : first_num);
				check[i] = 0;
			}
		}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	f(0, 0, -1);
	print(arrMax);
	cout << "\n";
	print(arrMin);
}
