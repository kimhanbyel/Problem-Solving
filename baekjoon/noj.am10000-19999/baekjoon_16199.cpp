#include <iostream>
using namespace std;

long long birth_date[3], now_date[3];
int main(){
	cin >> birth_date[0] >> birth_date[1] >> birth_date[2];
	cin >> now_date[0] >> now_date[1] >> now_date[2];
	
	
	if(now_date[1]>birth_date[1] || (now_date[1]==birth_date[1] && now_date[2]>=birth_date[2])) cout << now_date[0]-birth_date[0] << "\n";
	else cout << now_date[0]-birth_date[0]-1 << "\n";
	cout << now_date[0]-birth_date[0]+1 << "\n"; // 세는 나이
	cout << now_date[0]-birth_date[0];
}