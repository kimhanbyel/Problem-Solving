#include <iostream>
#include <algorithm>
using namespace std;

int n, m, p;
int arr[8], s[8];
void f(int num, int cnt){
	if(cnt == m){
		for(int i=0; i<m; i++)
			cout << s[i] << " ";
		cout << '\n';
		return;
	}
	
	int p = 0;
	for(int i=num; i<n; i++){
		if(arr[i] == p) continue;
		
		s[cnt] = arr[i];
		p = s[cnt];
		f(i, cnt+1);
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
	sort(arr, arr+n);
		
	f(0, 0);
}