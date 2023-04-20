#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, p[100001], visited[100001];
vector<int> v[100001];
void bfs(){
	queue<int> q;
	visited[1]++;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto value:v[x]){
			int nx = value;
			
			if(visited[nx]) continue;
			visited[nx]++;
			p[nx] = x;
			q.push(nx);
		}
	}
}
int main(){
	cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	for(int i=2; i<=n; i++){
		cout << p[i] << "\n";
	}
}