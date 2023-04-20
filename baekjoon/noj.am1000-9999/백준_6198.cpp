#include <iostream>
#include <stack>
using namespace std;

long long n, a, ans;
stack<long long> s;
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		while(!s.empty() && s.top()<=a) s.pop();
		
		ans += s.size();
		s.push(a);
	}
	cout << ans;
}
