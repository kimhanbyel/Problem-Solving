#include <iostream>
#include <stack>
using namespace std;

long long a, n, ans, cnt;
stack<pair<long long, long long>> s;
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a; cnt=1;
		while(!s.empty() && s.top().first <= a){
			ans += s.top().second;
			if(s.top().first == a) cnt = s.top().second+1;
			s.pop();
		}
		if(!s.empty()) ans++;
		s.push({a, cnt});
	}
	cout << ans;
}
