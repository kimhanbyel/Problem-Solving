#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;
int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++) q.push(i);
	cout << "<";
	for(int i=1; !q.empty(); i++){
		if(i==k){
			cout << q.front();
			if(q.size()>=2) cout << ", ";
			q.pop();
			i -= k;
		}
		else{
			q.push(q.front());
			q.pop();
		}
	}
	cout << ">";
} 
