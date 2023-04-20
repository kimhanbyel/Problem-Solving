#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;

int n, m, a, b, c, d, ans=1;
int light[101][101];
int visited[101][101];
int ansvisit[101][101];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
vector<pair<int,int>> v[101][101];
void bfs(){
	queue<pair<int,int>> q;
	q.push({1, 1});
	visited[1][1]++;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop();
		for(auto i:v[x][y]){
			if(visited[i.x][i.y]) continue;
			for(int idx=0; idx<4; idx++){
				int nx = i.x + dx[idx];
				int ny = i.y + dy[idx];
				
				if(nx<1 || ny<1 || nx>n || ny>n) continue;
				if(visited[nx][ny]){
					q.push({i.x, i.y});
					visited[i.x][i.y]++;
					break;
				}
			}
//			cout << i.x << " " << i.y << "\n";
			light[i.x][i.y]=1;
		}
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<1 || ny<1 || nx>n || ny>n) continue;
			if(visited[nx][ny] || light[nx][ny]==0) continue;
			
			q.push({nx, ny});
			visited[nx][ny]++;
		}
	}		
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		cin >> a >> b >> c >> d;
		v[a][b].push_back({c, d});
	}
	
	bfs();
			
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			ans += light[i][j];
//			cout << light[i][j] << " ";
		}
//		cout << "\n";
	}
	
	cout << ans;
}