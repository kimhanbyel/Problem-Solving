#include <iostream>
#include <queue>
using namespace std;

long long bfs(long long a, long long b){
	queue<pair<long long , long long>> q;
	q.push({a, 1});
	long long ans;
	
	while(!q.empty()){
		long long  nx, x = q.front().first, y=q.front().second;
		q.pop();
		
//		cout << x << " " << y << "\n";
		ans = y;
		if(x == b){
			return ans;
		}
		for(int i=0; i<2; i++){
			if(i==0) nx = x * 2;
			else nx = x*10+1;
			
			if(nx > b) continue;
			q.push({nx, y+1});
		}
	}
	return -1;
}

int main(){
	long long a, b;
	cin >> a >> b;
	cout << bfs(a, b);
}