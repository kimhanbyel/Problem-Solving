#include <iostream>
#include <queue>
using namespace std;

int T, l, KH[2], TG[2], V[301][301];
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {2, 2, 1, 1, -1, -1, -2, -2};

struct S{
	int x;
	int y;
	int c;
};

int bfs(int a, int b){
	int ans = 0;
	queue<S> q;
	q.push({a, b, 0});
	V[a][b]++;
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().c;
		
//		p(x, y, q.front().c);
		if(x == TG[0] && y == TG[1]){
			ans = cnt;
			break;
		}
			
		q.pop();
		for(int i=0; i<8; i++){			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=l || ny>=l || V[nx][ny])
				continue;
				
			q.push({nx, ny, cnt+1});
			V[nx][ny]++;
		}
	}
	return ans;
}

int main(){
	cin >> T;
	while(T--){
		cin >> l >> KH[0] >> KH[1] >> TG[0] >> TG[1];
		cout << bfs(KH[0], KH[1]) << '\n';
		
		for(int i=0; i<=l; i++){
			for(int j=0; j<=l; j++){
				V[i][j] = 0;
			}
		}
	}
}