#include <iostream>
using namespace std;

int T, n, dp[2][100111];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0; i<2; i++)
			for(int j=1; j<=n; j++){
				cin >> dp[i][j];
			}
			
		for(int i=2; i<=n; i++){
			dp[0][i] += max(dp[1][i-1], dp[1][i-2]);
			dp[1][i] += max(dp[0][i-1], dp[0][i-2]);
		}
		
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}