#include <iostream>
using namespace std;

int arr[51][51]={};
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};

void f(int i, int j){
	for(int rept=0; rept<8; rept++)
		arr[i+dx[rept]][j+dy[rept]]++;
}

int main(){
	int w, h, n, x, y;
	cin >> w >> h >> n;
	for(int i=0; i<n; i++){
		scanf("(%d,%d)", &x, &y);
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
}
