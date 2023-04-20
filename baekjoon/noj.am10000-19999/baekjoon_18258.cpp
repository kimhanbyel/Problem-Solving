#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n;
	string a;
	queue<int> q;
	cin >> T;
	while(T--){
		cin >> a;
		if(a=="push"){
			cin >> n;
			q.push(n);
			continue;
		}
		else if(a=="pop"){
			if(!q.empty()){
				cout << q.front();
				q.pop();
			}
			else
				cout << -1;
		}
		else if(a=="size"){
			cout << q.size();
		}
		else if(a=="empty"){
			cout << q.empty();
		}
		else if(a=="front"){
			if(!q.empty()){
				cout << q.front();
			}
			else
				cout << -1;
		}
		else if(a=="back"){
			if(!q.empty()){
				cout << q.back();
			}
			else
				cout << -1;
		}
		cout << "\n";
	}
}