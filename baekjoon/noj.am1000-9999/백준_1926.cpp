#include <iostream>
#include <queue>
using namespace std;

int a, b, cnt, maxCnt, arr[501][501];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
queue<pair<int,int>> q;
void bfs(int sI, int sJ){
	int bfsCnt = 0;
	q.push({sI, sJ});
	arr[sI][sJ] = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		bfsCnt++;
		
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
		
			if(nx>=0 && ny>=0 && nx<a && ny<b && arr[nx][ny]){
				q.push({nx, ny});
				arr[nx][ny] = 0;
			}
		}
	}
	maxCnt = max(maxCnt, bfsCnt);
}
int main(){
	cin >> a >> b;
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			cin >> arr[i][j];
	// O(n²)
	
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			if(arr[i][j] == 1){
				cnt ++;
				bfs(i, j);
			}
	// O(2n²)
	
	cout << cnt << "\n" << maxCnt;
}
