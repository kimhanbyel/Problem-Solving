#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int m = arr[0];
    int mi = 0;
    for(int i=0; i<arr.size(); i++)
    	if(arr[i] < m){
    		m = arr[i];
    		mi = i;
		}
		
    for(int i=0; i<arr.size(); i++)
    	if(i != mi) answer.push_back(arr[i]);
    
    if(answer.empty()) answer.push_back(-1);
    return answer;
}