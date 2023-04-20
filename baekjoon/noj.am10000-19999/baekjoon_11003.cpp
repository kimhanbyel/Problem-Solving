#include <iostream>
#include <deque>
using namespace std;

int n, l, a;
deque<pair<int,int>> d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> l;
	for(int i=0; i<n; i++){
		cin >> a;
		if(!d.empty() && i==d.front().second+l) d.pop_front();
		while(!d.empty() && d.back().first>a) d.pop_back();
		d.push_back({a, i});
		cout << d.front().first << " ";
	}
}