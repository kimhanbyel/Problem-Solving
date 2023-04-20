#include <iostream>
#include <queue>
using namespace std;

int n, ans=1000000, p=1, arr[101][101], visited[101][101];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

struct S{
	int x, y, z;
};

int check(int a, int b){
	for(int i=0; i<4; i++)
		if(!arr[a+dx[i]][b+dy[i]])
			return 1;
		
	return 0;
}

void bfs(int a, int b, int p, int s){
	queue<S> q;
	q.push({a, b, 0});
	visited[a][b]++;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=n || ny>=n || visited[nx][ny]) continue;
			if(s==0 && arr[nx][ny]==0) continue;
			if(s==1 && arr[nx][ny]==p) continue;
			
			if(s==0){
				arr[nx][ny] = p;
				q.push({nx, ny, 0});
				visited[nx][ny]++;
			}
			else{
				if(arr[nx][ny]==0){
					visited[nx][ny]++;
					q.push({nx, ny, z+1}); 
				}
				else if(arr[nx][ny]!=p){
					ans = min(ans, q.front().z);
				}
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			cin >> arr[i][j];
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(!visited[i][j] && arr[i][j]==1)
				bfs(i, j, p++, 0);
	
	fill(&visited[0][0], &visited[100][100], 0);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){ // O(n^4)
			if(arr[i][j]>=1 && check(i, j)){
				fill(&visited[0][0], &visited[100][100], 0);
				bfs(i, j, arr[i][j], 1);
			}
		}
	}
}