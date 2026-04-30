/**
* @file Arpa’s_obvious_problem_and_Mehrdad’s_terrible_solution.cpp
* https://codeforces.com/problemset/problem/742/B
*
* Created on 2024-10-10 at 16:38:21
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

/* 
    a^b = x ->
    x^a^b = 0 ->
    x^a = b

    [1]
        Mesmo que x < 1e5 e a < 1e5, podemos ter
        x ^ a > 1e5    

 */


#define MAX_A 100000 

int main() { _
    int n, x;
    cin >> n >> x;

    // guarda a qnst vzs o numero apareceu
    vector<int> qtd(MAX_A + 1);

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        qtd[vec[i]]++;
    }

    // guarda se o numero ja foi utilizado
    vector<int> used(MAX_A + 1);
    ll cnt = 0;

    for (int a : vec) {
        if (!used[a]) {
            used[a] = true;

            int b = (x^a);
            if (b > MAX_A) continue; // [1]!!!
            if (qtd[b] > 0) {
                used[b] = true;

                if (a == b) cnt += ((ll) qtd[b] * (qtd[b] - 1)) / 2;
                else cnt += (ll) qtd[b] * qtd[a];
            }
        }
    }

    cout << cnt << endl;

    return 0;
}