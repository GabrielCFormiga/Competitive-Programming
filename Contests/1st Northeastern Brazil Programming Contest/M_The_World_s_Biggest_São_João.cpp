#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string a, b; cin >> a >> b;

    vector<int> G;
    vector<int> R;
    vector<pair<int, char>> bad;

    for (int i = 0; i < n; i++){
        if (a[i] == b[i]){
            if (a[i] == 'G') G.push_back(i);
            else R.push_back(i);
        }
        else {
            bad.push_back({i, b[i]}); 
        }
    }

    ll g = G.size(), r = R.size();
    
    ll g1_g = 0, g1_r = 0;
    ll g2_g = 0, g2_r = 0;
    for (int i = 0; i < bad.size(); i++){
        g2_r += bad[i].second == 'R';
        g2_g += bad[i].second == 'G';
    }

    auto form = [&](){
        ll gg = (g + g1_r) * (g + g1_g - g1_r) + g1_g * (g1_r - g1_g - g);
        ll rr = (r + g2_g) * (r + g2_r - g2_g) + g2_r * (g2_g - g2_r - r);

        return gg + rr;
    };

    ll ans = form();

    // boto tudo no grupo de G
    for (int i = 0; i < bad.size(); i++){
        if (bad[i].second == 'R'){
            g1_r++;
            g2_r--;
        }
        else {
            g1_g++;
            g2_g--;
        }
        ans = max(ans, form());
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}