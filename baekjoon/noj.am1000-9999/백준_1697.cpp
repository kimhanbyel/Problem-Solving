#include <iostream>
#include <queue>
using namespace std;


int bfs(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, 0});
	int ans, visited[100001]={};
	visited[a]++;
	
	while(!q.empty()){
		int nx, m=100001, qp=100001, x = q.front().first, y=q.front().second;
		q.pop();
		
		ans = y;
		if(x == b) break;
		for(int i=0; i<3; i++){
			if(i==0) nx = x + 1;
			else if(i==1) nx = x - 1;
			else nx = x * 2;
			
			if(nx<0 || nx>100000 || visited[nx]) continue;
			q.push({nx, y+1});
			visited[nx]++;
		}
	}
	return ans;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << bfs(a, b);
}