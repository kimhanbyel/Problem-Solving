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
	int w=0, h=0, n=0;
	char str[100]={};
	cin >> w >> h >> n;
	for(int i=0; i<n; i++){
		cin >> str;
		
		int x=0, y=0, qwer = 0;
		for(int s=0; s<100; s++){
			if(str[s]>='0' && str[s]<='9'){
				if(str[s-1]>='0' && str[s-1]<='9'){
					if(qwer)
						y *= 10;
					else
						x *= 10;
				}
				if(qwer)
					y += str[s]-'0';
				else
					x += str[s]-'0';
			}
			else if(str[s] == ',')
				qwer++;
			else if(str[s] == ')')
				break;
		}
		
		arr[y][x] = 10;
	}
	
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			if(arr[i][j] >= 10)
				f(i, j);
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(arr[i][j] < 10) cout << arr[i][j];
			else cout << "X";
		}
		cout << endl;
	}
	
	return 0;
}
