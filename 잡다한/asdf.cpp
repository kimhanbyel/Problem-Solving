#include <iostream>
#include <math>
#include <vector>
using namespace std;

int k;
vector<int> arr;
vector<int> ans[10];
void f(int i, int floor, int ki, int p){
	if(ki==0 && p==0){
		floor++, ki++;
		ans[floor].push_back(arr[i]);
	}
	
		
}
int main(){
	cin >> k;
	for(int i=1; i<pow(2, k)-1; i++)
		cin >> arr[i];
		
	f(0, 0, 0, 0);
}
