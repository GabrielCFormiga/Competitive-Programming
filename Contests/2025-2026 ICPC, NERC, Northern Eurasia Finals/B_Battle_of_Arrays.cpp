#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    priority_queue<int> A, B;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        A.push(x);
    }

    for (int i = 0; i < m; i++){
        int y; cin >> y;
        B.push(y);
    }

    bool vez = true;
    while(!A.empty() && !B.empty()){
        int x = A.top();
        int y = B.top();

        A.pop();
        B.pop();

        if (vez){
            if (x >= y){
                A.push(x);
            }
            else {
                A.push(x);
                B.push(y-x);
            }
        }
        else {
            if (y >= x){
                B.push(y);
            }
            else {
                B.push(y);
                A.push(x-y);
            }
        }
        vez ^= 1;
    }

    if (A.empty()) cout << "Bob" << "\n";
    else cout << "Alice" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}