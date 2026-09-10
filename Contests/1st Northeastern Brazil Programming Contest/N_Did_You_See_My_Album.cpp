#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2026;
double dp[MAX+2][MAX+2];

void solve(){
    int n; cin >> n;
    double p; cin >> p;

    for (int j = MAX; j >= 1; j--){
        double pp = (j == MAX ? 0.0 : p/100.0); 

        double jj = j;

        for (int i = j-1; i >= 0; i--){
            double ii = i;

            double x = (1.0 - pp) * (ii / jj);
            double y = pp * (ii / (jj+1.0)) * dp[i][j+1];
            double z = (1.0 - pp) * (1.0 - ii / jj) * dp[i+1][j];
            double w = pp * (1.0 - ii / (jj+1)) * dp[i+1][j+1];

            dp[i][j] = (1.0 + y + z + w) / (1.0 - x);
        }
    }

    cout << fixed << setprecision(10) << dp[0][n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
