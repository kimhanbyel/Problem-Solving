#include <iostream>
#include <queue>
using namespace std;

int a, b, nx, ans, visited[100001][3];
int bfs(){
	queue<pair<int, int>> q;
	q.push({a, 0});
	visited[a][0]++;
	visited[a][1]++;
	visited[a][2]++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		cout << x << " " << y << "\n";
		ans = y;
		if(x == b) break;
		for(int i=0; i<3; i++){
			if(i==0) nx = x + 1;
			if(i==1) nx = x - 1;
			if(i==2) nx = x * 2;
			
			if(nx<0 || nx>100000 || visited[nx][i]) continue;
			if(i==2){
				q.push({nx, y});
			}
			else{
				q.push({nx, y+1});
			} 
			visited[nx][i]++;
		}
	}
	return ans;
}

int main(){
	cin >> a >> b;
	cout << bfs();
}