#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
void solve(){
    int n; cin >> n;
 
    vector<string> s(n);
    for (auto &i : s) cin >> i;
 
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j += 2){
            if (s[i][j] == s[i][j+1] && s[i][j] == 'N') ans++;
            else {
                j--;
                continue;
            }
        }
    }
 
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}