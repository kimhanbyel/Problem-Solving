#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int k, floor_, arr[1024];
vector<int> ans[10];
void p(){
	for(int i=k-1; i>=0; i--){
		for(auto num : ans[i])
			cout << num;
			
		cout << '\n';
	}
}
void f(int i, int floor, int ki, int p){
	if(i == pow(2, k)-1)
		return;
	
	if(i==0){
		ans[floor].push_back(arr[i+1]); 
	}
	else if(ki==0 && p==0){
		floor++; ki++;
		ans[floor].push_back(arr[i+1]);
	}
	else if(ki==1 && p==0){
		if(floor_ == floor) p=1;
		if(floor>1) floor_ = floor-1;
		while(floor>1){
			floor--;
			ki = 0;
		}
			
		floor--; ki++;
		ans[floor].push_back(arr[i+1]);
		floor++;
	}
	else if(ki==2 && p==0){
		floor++;
		ans[floor].push_back(arr[i+1]);
		ki--;
	}
	else if(ki==2 && p==1){
		floor++; p--; i--;
	}
	
	f(i+1, floor, ki, p);
}
int main(){
	cin >> k;
	for(int i=1; i<=pow(2, k)-1; i++)
		cin >> arr[i];
		
	f(0, 0, 0, 0);
               
    p();
}
