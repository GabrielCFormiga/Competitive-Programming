#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    
    cin >> n;

    vector<int> c(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }

    int ans = 0;
    bool possible = true;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        if (k[i] > c[i]) possible = false;
        ans = max(ans, sum - c[i] + k[i]);
    }

    if (possible){
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}