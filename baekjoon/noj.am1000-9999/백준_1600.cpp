#include <iostream>
#include <queue>
using namespace std;

int k, w, h, arr[200][200], visited[200][200][30];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int hx[8]={1,2,2,1,-1,-2,-2,-1}, hy[8]={2,1,-1,-2,-2,-1,1,2};
void bfs(){
	queue<pair<pair<int,int>,pair<int,int>>> q;
	visited[0][0][0]++;
	q.push({{0,0},{0,0}});
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int m = q.front().second.first;
		int c = q.front().second.second;
		
		q.pop();
		if(x==h-1 &&  y==w-1){
			cout << m;
			return;
		}
		if(c<k){
			for(int i=0; i<8; i++){
				int nx = x + hx[i];
				int ny = y + hy[i];
				
				if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
				if(visited[nx][ny][c+1] || arr[nx][ny]) continue;
			
				q.push({{nx, ny}, {m+1, c+1}});
				visited[nx][ny][c+1]++;
			}
		}
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
			if(visited[nx][ny][c] || arr[nx][ny]) continue;
		
			q.push({{nx, ny}, {m+1, c}});
			visited[nx][ny][c]++;
		}
	}
	cout << -1;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k >> w >> h;
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			cin >> arr[i][j];
	
	bfs();
}