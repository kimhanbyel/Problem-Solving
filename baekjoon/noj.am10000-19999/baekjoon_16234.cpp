#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n, l, r, day, today_move;
int arr[50][50], visited[51][51];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
queue<pair<int,int>> q, mq;
void bfs(int a, int b){
	q.push({a, b});
	visited[a][b]++;
	
	int ns = 0, nc = 0; 
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		nc ++;
		ns += arr[x][y];
		mq.push({x, y});
		
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int diff = abs(arr[nx][ny]-arr[x][y]);
			
			if(nx<0 || ny<0 || nx>=n || ny>=n || visited[nx][ny]) continue;
			if(diff<l || diff>r) continue; 
			
			today_move = 1;
			q.push({nx, ny});
			visited[nx][ny]++;
		}
	}
	int value = floor(ns/nc);
	while(!mq.empty()){
		int x = mq.front().first;
		int y = mq.front().second;
		
		mq.pop();
		arr[x][y] = value;
	}
	
}
int main(){
	// 입력
	cin >> n >> l >> r;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	while(1){						
		today_move = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(!visited[i][j])
					bfs(i, j);
					
		if(!today_move) break;
		fill(&visited[0][0], &visited[50][50], 0);
		day++;
	}
	cout << day;
}