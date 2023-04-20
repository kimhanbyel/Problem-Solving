#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	int n, a[100001]={}, cnt=0, i=0;
	stack<int> s;
	vector<char> ans;
	
	cin >> n;
	while(n--){
		cin >> a[cnt];
		
		while(i<a[cnt]){
			s.push(++i);
			ans.push_back('+');
		}
		if(s.top() == a[cnt]){
			ans.push_back('-');
			s.pop();
		}
		else{
			cout << "NO";
			return 0;
		}
	}
	
	for(auto a:ans)
		cout << a << "\n";
}
