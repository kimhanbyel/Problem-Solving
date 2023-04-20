#include <iostream>
using namespace std;

int a, b, c;
char d, e;
int main(){
	cin >> a >> d >> b >> e >> c;
	if(a+b==c) cout << "YES";
	else	   cout << "NO";
}

/* scanf
#include <iostream>
using namespace std;

int a, b, c;
int main(){
	scanf("%d + %d = %d", &a, &b, &c);
	if(a+b==c) cout << "YES";
	else	   cout << "NO";
}
*/

/* short coding
#include <cstdio>
int a, b, c;int main(){scanf("%d + %d = %d", &a, &b, &c);printf("%s",a+b-c?"NO":"YES");}
*/