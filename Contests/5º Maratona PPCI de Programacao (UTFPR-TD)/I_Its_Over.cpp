#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e7+5;

// primo
vector<bool> crivo(MAX, true);

void solve(){
    int n; cin >> n;

    vector<int> ans;

    for (int i = 0; i < n; i++){
        int m; cin >> m;
        int sum = 0;
        for (int i = 1; i <= m; i++){
            int x; cin >> x;

            if (crivo[i]){
                sum += x;
            }
        }

        if (crivo[sum]){
            ans.push_back(sum);
        }
    }

    if (ans.size() == 0){
        cout << "ITS OVER SOBROU NADA PRO BETINHA" << "\n";
        return;
    }

    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo[0] = 0;
    crivo[1] = 0;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i]){
            for (ll j = i * i; j < MAX; j += i){
                crivo[j] = false;
            }
        }
    }
    solve();
}