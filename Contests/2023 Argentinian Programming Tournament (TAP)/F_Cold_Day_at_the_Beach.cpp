#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll dist(ll x1, ll y1, ll x2, ll y2){
    return (abs(x1-x2) * abs(x1-x2) + abs(y1-y2) * abs(y1-y2));
}

void solve(){
    int n; cin >> n;

    ll d1, d2, x, y; cin >> d1 >> d2 >> x >> y;

    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    vector<pair<ll, ll>> b(n);
    for (int i = 0; i < n; i++){
        cin >> b[i].first >> b[i].second;
    }

    vector<ll> dist_a;
    for (int i = 0; i < n; i++){
        dist_a.push_back(dist(a[i].first, a[i].second, x, y));
    }
    vector<ll> dist_b;
    for (int i = 0; i < n; i++){
        dist_b.push_back(dist(b[i].first, b[i].second, x, y));
    }

    sort(dist_a.begin(), dist_a.end());
    sort(dist_b.begin(), dist_b.end());

    ll ans = 0;
    char c;
    if (dist_a[0] < dist_b[0]){
        c = 'A';
        ans++;
        int i = 1;
        while (i < n && dist_a[i] < dist_b[0]) {
            i++;
            ans++;
        }
    }
    else {
        c = 'R';
        ans++;
        int i = 1;
        while (i < n && dist_b[i] < dist_a[0]) {
            i++;
            ans++;
        }
    }

    cout << c << " " << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}