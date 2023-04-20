#include <iostream>
#include <stack>
using namespace std;

long long a, n, ans;
stack<pair<long long, long long>> s;
int main(){
	while(1){
		cin >> n;
		if(n == 0) return 0;
		for(int i=0; i<n; i++){
			cin >> a;
			int index = i;
			while(!s.empty() && a <= s.top().first){
				ans = max(ans, s.top().first*(i-s.top().second));
				index = s.top().second;
				s.pop();
			}
			s.push({a, index});
		}
		while(!s.empty()){
			ans = max(ans, s.top().first*(n-s.top().second));
			s.pop();
		}
		cout << ans << '\n';
		ans = 0;
	}
}