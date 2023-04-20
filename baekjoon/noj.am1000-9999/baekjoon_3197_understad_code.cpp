#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int r, c, visited[1500][1500];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
char arr[1500][1500];
pair<int,int> swan_pos;
queue<pair<int, int>> q, swanq, waterq;

void bfs();
int main(){
	cin >> r >> c;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++){
			cin >> arr[i][j];
			if(arr[i][j]=='L') swan_pos = {i, j};
			if(arr[i][j]!='X') waterq.push({i, j});
		}
	
	swanq.push(swan_pos);
	visited[swan_pos.first][swan_pos.second]++;
	bfs();
}

void bfs(){
	int day = 0;
	while(1){
		queue<pair<int, int>> next_swanq;
		while(!swanq.empty()){
			int x = swanq.front().first;
			int y = swanq.front().second;
			
			swanq.pop();
			if(arr[x][y]=='L' && (x!=swan_pos.first || y!=swan_pos.second)){
				cout << day;
				return;
			}
			for(int i=0; i<4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx<0 || ny<0 || nx>=r || ny>=c || visited[nx][ny]) continue;
					
				visited[nx][ny]++;
				if(arr[nx][ny]=='X') next_swanq.push({nx, ny});
				else swanq.push({nx, ny});
			}
		}
		swanq = next_swanq;
		day++;
		
		int wsize = waterq.size();
		while(wsize--){
			int x = waterq.front().first;
			int y = waterq.front().second;
			
			waterq.pop();
			for(int i=0; i<4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
				if(arr[nx][ny]!='X') continue;
				
				arr[nx][ny]='.';
				waterq.push({nx, ny}); 
			}
		}
		cout << day << "\n";
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++)
				cout << arr[i][j];
			cout << "\n";
		}	cout << "\n" ;
	}
}