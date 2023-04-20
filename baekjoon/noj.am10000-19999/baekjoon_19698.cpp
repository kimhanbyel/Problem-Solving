#include <iostream>
using namespace std;

int main(){
	long long n, w, h, l;
	cin >> n >> w >> h >> l;
	int ans = (w/l) * (h/l);
	if(n < ans) cout << n;
	else		cout << ans;
}