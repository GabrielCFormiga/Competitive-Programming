#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

const int MAXN = 1010;

int n, m;
int ans = 0;

char R[MAXN][MAXN];
char E[MAXN][MAXN];
vector<string> og, eg;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << R[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void equal() {
    // print();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (R[i][j] != og[i][j]) return;
        }
    }
    ans++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;
    
    og.resize(n);

    for (int i = 0; i < n; i++) {
        cin >>  og[i];
    }

    // NORMAL
    // R1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            R[i][j] = og[i][j];
        }
    }
    equal();

    // R2
    if (n == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                R[i][j] = og[n - 1 - j][i];
            }
        }
        equal();
    }

    // R3
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            R[i][j] = og[n - 1 - i][m - 1 - j];
        }
    }
    equal();
    
    // R4
    if (n == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                R[i][j] = og[j][n - 1 - i];
            }
        }
        equal();
    }

    // ESPELHADO
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            E[i][j] = og[i][m - 1 - j];
        }
    }

    // R1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            R[i][j] = E[i][j];
        }
    }
    equal();

    // R2
    if (n == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                R[i][j] = E[n - 1 - j][i];
            }
        }
        equal();
    }

    // R3
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            R[i][j] = E[n - 1 - i][m - 1 - j];
        }
    }
    equal();
    
    // R4
    if (n == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                R[i][j] = E[j][n - 1 - i];
            }
        }
        equal();
    }

    cout << ans << endl;
}