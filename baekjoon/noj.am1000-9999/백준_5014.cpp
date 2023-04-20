#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d, nx, ans=-1, arr[1000001], visited[1000001];
void bfs(){
	queue<pair<int, int>> q;
	q.push({s, 0});
	visited[s]++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		if(x == g){
			ans = y;
			break;
		}
		q.pop();
		for(int i=0; i<2; i++){
			if(i==0) nx = x + u;
			else	 nx = x - d;
			
			if(nx<1 || nx>f || visited[nx]) continue;
			q.push({nx, y+1});
			visited[nx]++; 
		}
	}
}
int main(){
	cin >> f >> s >> g >> u >> d;
	bfs();
	
	if(ans == -1) cout << "use the stairs";
	else		  cout << ans;
}

/*
f floor
s my floor
g go_to_here
u myfloor += up
d myfloor -= down
*/