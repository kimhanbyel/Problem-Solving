#include <iostream>
using namespace std;

int arr[51][51]={};
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};

void f(int i, int j){
	for(int rept=0; rept<8; rept++)
		arr[i+dx[rept]][j+dy[rept]]++;
		
	return;
}

int main(){
	char c[4]={};
	int w, h, n, x, y;
	cin >> w >> h >> n;
	for(int i=0; i<n; i++){
		scanf("%1c%d%1c%d%1c", &c[0], &x, &c[1], &y, &c[2]);
		arr[x][y] = 10;
	}
	
	for(int i=0; i<w; i++)
		for(int j=0; j<h; j++)
			if(arr[i][j] >= 10)
				f(i, j);
	
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			if(arr[i][j] < 10) cout << arr[i][j];
			else cout << "X";
		}
		cout << endl;
	}
	
	return 0;
}
