#include <iostream>
#include <queue>
using namespace std;

int n, m, h, arr[301][301], visited[301][301], dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};

void f(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) // 90000
			cout << arr[i][j] << " ";
			
		cout << "\n";
	} cout << "\n";
}
void bfs(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b]++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=n || ny>=m || visited[nx][ny] || arr[nx][ny] > h) continue;
			q.push({nx, ny});
			visited[nx][ny]++;
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) // 90000
			cin >> arr[i][j];
			
	for(h=0; h<=20; h++){
		int path = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){ // 990000
				f();
				if(!visited[i][j] && arr[i][j]>h){
					bfs(i, j);
					path ++;
					if(path >= 2){
						cout << path;
						return 0;
					}
				}
			}
		}
		for(int i=0; i<n; i++) 
			for(int j=0; j<m; j++) // 1,890,000
				visited[i][j] = 0;
	}
	
	cout << 0;
}