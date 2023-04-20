#include <iostream>
#include <queue>
using namespace std;

int l, r, c, SP[3], EP[3];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int visit[30][30][30];
char map[30][30][30];

struct S{
	int x;
	int y;
	int z;
	int time;
};

void fill(){
	for(int h=0; h<l; h++)
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				visit[i][j][h] = 0;
}

void bfs(){
	queue<S> q;
	q.push({SP[0], SP[1], SP[2], 0});
	visit[SP[0]][SP[1]][SP[2]]++;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int t = q.front().time;
		
		q.pop();
		if(x==EP[0] && y==EP[1] && z==EP[2]){
			cout << "Escaped in " << t << " minute(s).\n";
			return;
		}
		for(int i=0; i<6; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			
			if(nx<0 || ny<0 || nz<0 || nx>=r || ny>=c || nz>=l) continue;
			if(visit[nx][ny][nz] || map[nx][ny][nz]=='#') continue;
			
			q.push({nx, ny, nz, t+1});
			visit[nx][ny][nz]++;
		}
	}
	cout << "Trapped!\n";
}

int main(){
	while(1){
		cin >> l >> r >> c;
		if(l+r+c == 0){
			break;
		}
		 
		for(int h=0; h<l; h++){
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){ // 
					cin >> map[i][j][h];
					if(map[i][j][h] == 'S'){
						SP[0] = i, SP[1] = j, SP[2] = h;
					}
					if(map[i][j][h] == 'E'){
						EP[0] = i, EP[1] = j, EP[2] = h;
					}
				}
			}
		}
		bfs();
		fill();
	}
}