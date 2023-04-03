#include <iostream>
using namespace std;

int n, m, ans, a[1000001], b[1000001]; 
int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    
    for(int i=0; i<n; i++){
        if(m-a[i]>0 && b[m-a[i]]) ans++;
        b[a[i]]++;
		}
    
    cout << ans;
}
