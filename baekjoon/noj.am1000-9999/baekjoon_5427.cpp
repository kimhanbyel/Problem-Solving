#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, sx, sy;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int fireArr[1000][1000], visited[1000][1000][2];
char arr[1000][1000];
vector<pair<int,int>> firePos;

struct S{
	int x;
	int y;
	int sec;	
};

void fireBFS(){
	queue<S> q;
	while(!firePos.empty()){
		int x = firePos.back().first, y = firePos.back().second;
		q.push({x, y, 0});
		visited[x][y][0]++;
		firePos.pop_back();
	}
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int s = q.front().sec;
		
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=n || ny>=m || visited[nx][ny][0] || arr[nx][ny]=='#') continue;
			q.push({nx, ny, s+1});
			fireArr[nx][ny] = s + 1;
			visited[nx][ny][0]++;
		}
	}
}
void BFS(){
	queue<S> q;
	q.push({sx, sy, 0});
	visited[sx][sy][1]++;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int s = q.front().sec;
		
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=n || ny>=m){
				cout << s+1 << "\n";
				return;	
			}
			if(visited[nx][ny][1] || (fireArr[nx][ny]!=0 && fireArr[nx][ny]<=s+1) || arr[nx][ny]!='.') continue;
			q.push({nx, ny, s+1});
			visited[nx][ny][1]++;
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			if(arr[i][j]=='F') firePos.push_back({i, j});
			else if(arr[i][j]=='J') sx = i, sy = j;
		}
	}
	fireBFS();
	BFS();
}