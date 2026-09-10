/**
* @file C_Rental_Service.cpp
*
* Created on 2026-09-10 at 02:24:09
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void setIO(string name = "") {
    if(name.size()) {
        (void)freopen((name + ".in").c_str(), "r", stdin);
        (void)freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() { _
    setIO("rental");

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.rbegin(), cows.rend());

    vector<ll> prefix_cows(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix_cows[i] = prefix_cows[i - 1] + cows[i - 1];
    } 

    vector<pair<int, int>> buy(m); // {qnt, price}

    for (int i = 0; i < m; i++) {
        cin >> buy[i].first >> buy[i].second;
    }

    sort(buy.begin(), buy.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first > b.first; 
        } 
        return a.second > b.second;
    });

    vector<pair<ll, ll>> prefix_buy(m + 1); // {total_qnt, total_qnt * price}
    for (int i = 1; i <= m; i++) {
        prefix_buy[i] = {
            prefix_buy[i - 1].first + buy[i - 1].first,
            prefix_buy[i - 1].second + 1ll * buy[i - 1].first * buy[i - 1].second
        };
    }

    vector<int> rent(r);

    for (int i = 0; i < r; i++) {
        cin >> rent[i];
    }

    sort(rent.rbegin(), rent.rend());

    vector<ll> prefix_rent(r + 1);
    for (int i = 1; i <= r; i++) {
        prefix_rent[i] = prefix_rent[i - 1] + rent[i - 1];
    } 

    ll ans = 0;

    for (int x = 0; x <= n; x++) {
        // x = qtd cows to be milked

        ll curr = prefix_rent[min(r, n - x)];  

        ll milk = prefix_cows[x];

        int left = 0, right = m;
        int mid;
        
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (prefix_buy[mid].first > milk) right = mid - 1; 
            else left = mid;
        }

        curr += prefix_buy[left].second;
        milk -= prefix_buy[left].first;

        if (milk > 0 && left < m) {
            curr += milk * buy[left].second;
        }

        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}