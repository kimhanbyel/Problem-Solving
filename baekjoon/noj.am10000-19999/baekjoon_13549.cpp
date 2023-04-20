#include <iostream>
#include <queue>
using namespace std;

int a, b, nx, visited[100001];
void bfs(){
	queue<pair<int,int>> q;
	q.push({a, 0});
	visited[a]++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		if(x == b){
			cout << y;
			return;
		}
		for(int i=0; i<3; i++){
			if(i==0) nx = x * 2;
			else if(i==1) nx = x - 1;
			else nx = x + 1;
			
			if(nx<0 || nx>100000 || visited[nx]) continue;
			if(i==0){
				q.push({nx, y});
			}
			else{
				q.push({nx, y+1});
			}
			visited[nx]++;
		}
	}
	return;
}
int main(){
	cin >> a >> b;
	bfs();
}