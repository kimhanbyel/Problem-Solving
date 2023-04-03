#include <iostream>
#include <set>
using namespace std;

long long a, n;
set<int> s;
int main(){
	scanf("%lld", &n);
	while(n--){
		scanf("%lld", &a), s.insert(a);
	}
	scanf("%lld", &n);
	while(n--){
		scanf("%lld", &a), cout << s.count(a) << " ";
	}
}
