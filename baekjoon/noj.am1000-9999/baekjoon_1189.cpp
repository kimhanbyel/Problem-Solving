#include <iostream>
using namespace std;

int r, c, k, ans=0;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1}, check[6][6];
char arr[6][6];
void dfs(int i, int j, int move){
	if(i==0 && j==c-1 && move==k){
		ans++;
		return;
	}
	
	for(int l=0; l<4; l++){
		int nx=i+dx[l], ny=j+dy[l];
		if(check[nx][ny]) continue;
		if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
		if(arr[nx][ny]=='T') continue;
		
		check[nx][ny] = 1;
		dfs(nx, ny, move+1);
		check[nx][ny] = 0;
	}
}

int main(){
	cin >> r >> c >> k;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin >> arr[i][j];
	
	check[r-1][0] = 1;	
	dfs(r-1,0,1);
	cout << ans;
}
