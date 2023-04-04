// 상업경진대회 문제 1번 
#include <iostream> 
using namespace std;

int n=0;
double a=0.0, b=0.0, v=0.0, h=0.0, m=0.0, s=0.0;
int main(){
	cin >> n;
	
	for(int i=1; i<=n; i++){
		scanf("%lf %lf:%lf:%lf", &v, &h, &m, &s);
		
		m /= 60; s /= 3600;
		a += double(v*(h+m+s));
		b += double(h+m+s);
	}
	printf("%.2lf", a/b);
}
