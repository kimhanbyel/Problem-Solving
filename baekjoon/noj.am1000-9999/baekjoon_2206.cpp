#include <iostream>
#include <queue>
using namespace std;

int n, m, dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1}, arr[1001][1001], visited[1001][1001][2];
struct S{
	int x;
	int y;
	int c; 
	int wall_move;
};

//void f(int a, int b, int c, int wm){
//	cout << wm << "\n";
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=m; j++){
//			if(i==a && j==b)
//				cout << c << " "; 
//			else
//				cout << arr[i][j] << " ";
//		}
//		cout << "\n";
//	}	cout << "\n";
//}

int bfs(int a, int b, int ans=-1){
	queue<S> q;
	q.push({a, b, 1, 0});
	visited[a][b][0]++;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int c = q.front().c;
		int wm = q.front().wall_move;
//		f(x, y, c, wm); // 추력
		
		if(x == n && y == m){ ans = c; break; }
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<1 || ny<1 || nx>n || ny>m || visited[nx][ny][wm]) continue;
			if(wm == 0) {
				if(arr[nx][ny] == 0) q.push({nx, ny, c+1, 0});
				else q.push({nx, ny, c+1, 1});
				visited[nx][ny][wm]++;
			}
			else if(arr[nx][ny] == 0){
				q.push({nx, ny, c+1, wm});
				visited[nx][ny][wm]++;
			}
		}
	}
	return ans;
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	cout << bfs(1, 1);
}