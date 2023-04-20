#include <iostream>
using namespace std;

int n, ans, arr[1000], dp[1000]={1};
int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+1);
			else				dp[i] = max(dp[i], 1);
		}
		
		ans = max(ans, dp[i]);
	}
	cout << ans;
}