#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, a;
	vector<int> v;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), less<int>());
	for(auto b:v)
		cout << b << "\n";
}