#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    sort(arr.begin(), arr.end());

    int sum = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 1) sum++;
        else {
            if (i == n-1) sum++;
            else sum += 2;
        }
    }

    if (sum % 2) cout << "Alice" << "\n";
    else cout << "Bob" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}