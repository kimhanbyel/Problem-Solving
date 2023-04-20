#include <iostream>
#include <queue>
using namespace std;

int a, b, nx, ans, visited[100001], memo[100001];
void bfs(){
	queue<pair<int, int>> q;
	visited[a]++;
	q.push({a, 0});
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		if(x==b){
			ans = y;
			return;
		}
		for(int i=0; i<3; i++){
			if(i==0) nx = 2*x;
			else if(i==1) nx = x+1;
			else	 nx = x-1;
			
			if(nx<0 || nx>100000 || visited[nx]) continue;
			visited[nx]++;
			memo[y] = nx;
			q.push({nx, y+1}); 
		}
	}
}
int main(){
	cin >> a >> b;
	bfs();
	cout << ans << "\n";
	for(int i=0; i<ans; i++)
		cout << memo[i] << " ";
}