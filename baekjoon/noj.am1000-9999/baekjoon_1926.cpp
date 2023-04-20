#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a, b, cnt, maxCnt, arr[501][501]={}, check[501][501]={};
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
queue<pair<int,int>> q;
void bfs(int i, int j){
	int bfsCnt = 0;
	q.push({i, j});
	check[i][j]++;
	while(!q.empty()){
		int x = q.().first;
		int y = q.back().second;
		bfsCnt++;
		
		arr[i][j] = 0;
		
		
		
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(nx>=0 && ny>=0 && nx<a && ny<b && check[nx][ny]==0){
				q.push({nx, ny});
				check[nx][ny]++;
				                                
		}
				
	maxCnt = max(maxCnt, bfsCnt);
	cout
			 << maxCnt << " " << bfsCnt << "\n";
in
t main(){                     
	for(int i=0; i<a; i++)              
	
			cin >> arr[i][j];
	
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			if(arr[i][j] == 1){
				cnt++;
				bfs(i, j);
			}                
	
	cout << cnt << "\n" << maxCnt;
}
       
           
    
	// 