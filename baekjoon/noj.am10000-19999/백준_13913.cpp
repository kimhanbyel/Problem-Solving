#include <iostream>
#include <queue>
using namespace std;

int a, b, nx, ans, visited[100001];
int p[100001], print[100001];
void bfs(){
	queue<pair<int, int>> q;
	q.push({a, 0});
	visited[a]++;
	p[a] = -1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		if(x == b){
			ans = y;
			for(int i=0; x>=0; i++){
				print[i] = x;
				x = p[x];
			}
			return;
		}
		for(int i=0; i<3; i++){
			if(i==0) nx = 2*x;
			else if(i==1) nx = x+1;
			else nx = x-1;
			
			if(nx<0 || nx>100000 || visited[nx]) continue;
			q.push({nx, y+1});
			p[nx] = x;
			visited[nx]++;
		}
	}
}
int main(){
	cin >> a >> b;
	bfs();
	cout << ans << "\n";
	for(int i=ans; i>=0; i--){
		cout << print[i] << " ";
	}
}