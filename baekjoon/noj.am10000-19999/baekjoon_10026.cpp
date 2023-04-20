#include <iostream>
#include <queue>
using namespace std;

int n, RGBColor_ans[2], RGBvisited[101][101][2];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
char arr[101][101]={};
void bfs(int a, int b, int RGB, char RGBcode){
	queue<pair<int,int>> q;
	q.push({a, b});
	RGBvisited[a][b][RGB]++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=n || ny>=n || RGBvisited[nx][ny][RGB]) continue;
			if(RGB == 0 && arr[nx][ny] != RGBcode) continue;
			if(RGB == 1 && (((RGBcode=='R' || RGBcode=='G') && arr[nx][ny]=='B') || (RGBcode=='B' && arr[nx][ny]!='B'))) continue;
			RGBvisited[nx][ny][RGB]++;
			q.push({nx, ny});
		}
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
			
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			if(!RGBvisited[i][j][0]){
				bfs(i, j, 0, arr[i][j]);
				RGBColor_ans[0]++;
			}
			if(!RGBvisited[i][j][1]){
				bfs(i, j, 1, arr[i][j]);
				RGBColor_ans[1]++;
			}
		}
	
	cout << RGBColor_ans[0] << " " << RGBColor_ans[1];
}