#include <bits/stdc++.h>
using namespace std;

int freq[1000001], n, sum, cnt;
bool occur[2000001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> freq[i];
    cin >> sum;
    for (int i = 0; i < n; i++) {
        if (sum-freq[i] > 0 && occur[sum-freq[i]]) cnt++;
        occur[freq[i]] = true;
    }
	cout << cnt;
    return 0;
}
