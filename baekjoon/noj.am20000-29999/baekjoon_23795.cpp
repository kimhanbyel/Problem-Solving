#include <iostream>
using namespace std;

int a, b, c, d, e;
int main(){
	for(int i=3; i>=1; i--){
		cin >> a;
		d += a*i;
	}
	for(int i=3; i>=1; i--){
		cin >> a;
		e += a*i;
	}
	if(d>e) cout << "A";
	else if(d<e) cout << "B";
	else	cout << "T";
}

/* short coding
#include <iostream>
int a,b,c,d,e,f;int main(){std::cin>>a>>b>>c>>d>>e>>f;a=a*3+b*2+c,b=d*3+e*2+f;std::cout<<(a>b?"A":b>a?"B":"T");}
*/