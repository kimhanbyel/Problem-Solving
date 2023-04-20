#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, prv, check[11], nxt=1, arr[11];
vector<int> v[10];
int main(){
	cin >> k;
	for(int i=0; i<(1<<k)-1; i++){
		cin >> arr[i];
		v[nxt-1].push_back(arr[i]);
		
		prv = nxt;
		if(nxt!=k) check[nxt] = check[nxt]?0:1;
		if(check[prv] && !prv) nxt = 0;
		else				   nxt++;
	}
	
	for(int i=k-1; i>=0; i--){
		for(auto a : v[i])
			cout << a << " ";
			
		cout << '\n';
	}
}
