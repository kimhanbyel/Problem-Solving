#include <bits/stdc++.h>
using namespace std;

struct tomato{
	int y, x, z;
};
queue<tomato> q;

int dx[6]={1, -1, 0, 0, 0 ,0};
int dy[6]={0, 0, 1, -1, 0, 0};
int dz[6]={0, 0, 0, 0, 1, -1};

int n, m, h, r;
int arr[101][101][101]={};

bool check(int ny, int nx, int nz){
	return (0<=nx && 0<=ny && 0<=nz && nx<m && ny<n && nz<h);
}

//void print(){
//	for(int l=0; l<h; l++){
//		for(int i=0; i<n; i++){
//			for(int j=0; j<m; j++){
//				cout << arr[i][j][l] << " ";
//			}
//			cout << "\n";
//		}
//	}
//}

void bfs(){
	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int z = q.front().z;
		q.pop();
		
//		print();
//		cout << "\n";
		for(int i=0; i<6; i++){
			int ny= y+dy[i];
			int nx= x+dx[i];
			int nz= z+dz[i];
			
			if(check(ny, nx, nz)==1 && arr[ny][nx][nz]==0){
				arr[ny][nx][nz] = arr[y][x][z]+1;
				q.push({ny, nx, nz});
			}
		}
	}
}

int main(){
	cin >> m >> n >> h;
	
	for(int l=0; l<h; l++)
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				cin >> arr[i][j][l];
				if(arr[i][j][l]==1){
					q.push({i, j, l});
				}
			}
	
	bfs();
	for(int l=0; l<h; l++)
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j][l]==0){
					cout << -1;
					return 0;
				}
				if(r<arr[i][j][l]){
				   r=arr[i][j][l];
				}
			}
		}
	
	cout << r-1;
}