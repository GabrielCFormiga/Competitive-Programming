#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    int wins = 0;
    for (int i = 0; i < n; i++){
        if (arr[i]){
            ans++;
            wins++;
        }
        else if (!arr[i]){
            ans--;
            wins = 0;
        }
        if (wins >= 3){
            ans++;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}