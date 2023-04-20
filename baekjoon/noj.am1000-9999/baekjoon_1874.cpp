#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
int n, cnt, clear=1, arr[100001];
int main(){
	stack<int> s;
	vector<char> ans;
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		s.push(i);
		ans.push_back('+');
		
		for(;!s.empty();){
			if(s.top() == arr[clear]){
				ans.push_back('-');
				s.pop();
				clear++;
			}
			else
				break;
		}
	}
	
	if(s.empty())
		for(auto a : ans)
			cout << a << '\n';
	else
		cout << "NO";
	
}
