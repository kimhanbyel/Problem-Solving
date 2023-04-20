#include <iostream>
#include <stack>
using namespace std;

int n, a, c, p, arr; // c´Â size copy´Ù 
stack<pair<int, int> > s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){ // O(n)
		c = i;
		cin >> a;
		while(!s.empty()){ // O(N©÷) 
			if(s.top().first > a){ // O(1)
				p = s.top().second; // print = c
				break;
			}
			s.pop(); // O(1)
			c--;
		}
		
		cout << p << " ";
		s.push({a, i+1}), p=0;
	}
}
