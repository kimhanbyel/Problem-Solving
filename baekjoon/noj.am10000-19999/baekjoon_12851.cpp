#include <iostream>
#include <queue>
using namespace std;

int a, b, nx, ans1, ans2, visited[100001][100001];
void bfs(){
	queue<pair<int,int>> q;
	q.push({a, 0});
	visited[a][0]++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		if(x == b){
			if(!ans1) ans1 = y;
			if(ans1 == y) ans2++;
		}
		for(int i=0; i<3; i++){
			if(i==0) nx = x * 2;
			else if(i==1) nx = x - 1;
			else nx = x + 1;
			
			if(nx<0 || nx>100000 || visited[nx][y]) continue;
			q.push({nx, y+1});
		}
	}
	return;
}
int main(){
	cin >> a >> b;
	bfs();
	cout << ans1 << "\n" << ans2;
}

/*

5 4 8 16 17 = 4
5 10 9 18 17 = 4


*/