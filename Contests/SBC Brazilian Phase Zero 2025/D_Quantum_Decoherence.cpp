/**
* @file D_Quantum_Decoherence.cpp
*
* Created on 2025-06-11 at 18:54:49
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

int main() { _
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    // ans = qtd de qubits que colapsaram CNTP / qtd qubits que estavam em superposição no estado isolado    
    int colap = 0, super = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') super++;
        if (s[i] == '*' && t[i] != '*') colap++;
    }   

    cout << fixed << setprecision(2) << (float) colap / super << endl;

    return 0;
}