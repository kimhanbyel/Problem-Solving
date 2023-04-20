#include <iostream>
using namespace std;

int T, n, ans, arr[100001], check[100001], visited[100001];
void dfs(int i, int c[]){
//	for(int j=1; j<=n; j++){
//		cout << j << " " << c[j] << "\n";
//	}	cout << "\n";
	if(!c[i] && !visited[i]){
		c[i]++;
		dfs(arr[i], c);
		c[i]--;
	}
	else if(visited[i] == 0){
		ans--;
		visited[i]++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(T--){
		cin >> n;
		ans = n;
		
		for(int i=1; i<=n; i++){ visited[i]=0; cin >> arr[i];}
		for(int i=1; i<=n; i++) dfs(i, check);
		cout << ans << "\n";
	}
}

/*
2
7
3 1 3 7 3 4 6
8
1 2 3 4 5 6 7 8

1->3->3, 2->1->3->3, 3->3, 4->7->6->4->7->6, 5->3, 6->4->7->6->4->7, 7->6->4->7->6->4
1->1, 2->2, 3->3, 4->4, 5->5, 6->6, 7->7, 8->8
*/