#include <iostream>
#include <queue>
using namespace std;

int n, m, ans, nx, ny, piece;
int arr[301][301], Carr[301][301], visited[301][301];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int check(int a, int b){
	int zero_cnt = 0;
	for(int i=0; i<4; i++)
		if(arr[a+dx[i]][b+dy[i]]<=0)
			zero_cnt++;
	
	return zero_cnt;
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
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
			if(visited[nx][ny] || arr[nx][ny]<=0) continue;
			
			q.push({nx, ny});
			visited[nx][ny]++;
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){ // 90000
			cin >> arr[i][j];
			Carr[i][j] = arr[i][j];
		}
	
	for(int h=0; h<90000; h++){// X
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) // 540000*X O(2N²)
				if(arr[i][j]>0 && !visited[i][j]){
					bfs(i, j);
					piece++;
					if(piece>1){
						cout << h;
						return 0;
					}
				}
		if(piece == 0) break;
		 
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){ // (90000 + 90000)*X
				visited[i][j] = 0;
				if(arr[i][j]>0) // 450000*X
					Carr[i][j] = arr[i][j]-check(i, j);
				else if(arr[i][j] <= 0)
					Carr[i][j] = 0;
			}
			
		copy(&Carr[0][0], &Carr[0][0]+90000, &arr[0][0]);
		piece = 0;
	}
	cout << 0;
}