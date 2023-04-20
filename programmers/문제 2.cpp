#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmd(pair<int, double> a, pair<int, double> b){
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int arr[501]={};
    
    vector<pair<int, double>> v;
    for(auto a : stages) arr[a]++;
    for(int i=0, m=N; i<m; i++)
    	if(arr[i] != 0){
    		v.push_back({i,arr[i]/m});
    		m -= arr[i];
		}
		
	sort(v.begin(), v.end());
	for(auto a : v) answer.push_back(a.first);
		
    return answer;
}