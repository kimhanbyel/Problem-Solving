#include <iostream>
using namespace std;

int n, ans, arr[101]={};
bool erato(int a){
	if(a<=1) return 0;
	for(int i=2; i*i<=a; i++)
		if(a%i==0) return 0;
		
	return 1;
}

bool f(int s, int e){
	for(int i=s; i<=e; i++)
		for(int j=i+1; j<=e; j++)
			if(erato(i) && erato(j))
				return 1;
				
	return 0;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	for(int i=0; i<n-3; i++)
		if((arr[i]-arr[i+1] == arr[i+1]-arr[i+2]) &&
			arr[i+2]-arr[i+3])
				ans += f(i,i+3);
	
	cout << ans;
}

// 1 2 3 4 || 12 3 23 5 13 4 
