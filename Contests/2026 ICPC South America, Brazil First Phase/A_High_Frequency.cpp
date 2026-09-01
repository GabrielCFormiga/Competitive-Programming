#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<pair<ll, ll>> arr(n+1);
    for (int i = 1; i <= n; i++){
        ll x, y; cin >> x >> y;

        arr[i].first += x + arr[i-1].first;
        arr[i].second += y + arr[i-1].second;
    }

    int q; cin >> q;

    while(q--){
        int x; cin >> x;
        if (arr[x].first > arr[x].second){
            cout << "COMPRA" << "\n";
        }
        else if (arr[x].first == arr[x].second){
            cout << "NEUTRO" << "\n";
        }
        else cout << "VENDA" << "\n";
    }
}