#include <iostream>
using namespace std;

int arr[11][11]={};
int c[11][11]={};
int n, m=3003;

void f1(int a, int b, int d){
	c[a][b]+=d;
	c[a+1][b]+=d;
	c[a-1][b]+=d;
	c[a][b+1]+=d;
	c[a][b-1]+=d;
}

void how_much(){
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cout << c[i][j] << " ";
//		}
//		cout << endl;
//	}	cout << endl;
	
	int money = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(c[i][j]>0)
				money += arr[i][j];
				
	if(money < m) m = money;
}
void f2(int t){
	if(t == 3){
		how_much();
		return;
	}
	
	for(int i=1; i<n-1; i++){
		for(int j=1; j<n-1; j++){
			if(c[i][j]+c[i+1][j]+c[i-1][j]+c[i][j+1]+c[i][j-1] == 0){
				f1(i,j,1);	
				f2(t+1);
				f1(i,j,-1);
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
	
	f2(0);
	cout << m;
}
