/**
* @file Sliding_Window_Minimum.cpp
* @author GabrielCampelo
* Created on 2026-02-13 at 15:23:36
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX_N = 10000100;

int vec[MAX_N];

stack<pair<int,int>> s1, s2; 

void add(int value){
    int min_value;
    if(s1.empty()){
        min_value = value;
    } else {
        min_value = min(value, s1.top().second);
    }
    s1.push({value, min_value});
}

void rem(){
    int min_value;
    if(s2.empty()){    
        while(!s1.empty()){
            if(s2.empty()){
                min_value = s1.top().first;
            } else {
                min_value = min(s1.top().first, s2.top().second);
            }
            s2.push({s1.top().first, min_value});
            s1.pop();
        }
    }
    s2.pop();
}

int min_value(){
    int min_value;
    if(s1.empty() || s2.empty()){
        min_value = s1.empty() ? s2.top().second : s1.top().second; 
    } else {
        min_value = min(s1.top().second, s2.top().second);    
    } 
    return min_value;
}


int main() { _
    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vec[1] = x;
    for (int i = 2; i <= n; i++) {
        vec[i] = (1ll * a * vec[i - 1] + b) % c;
    }

    for (int i = 1; i <= k; i++) {
        add(vec[i]);
    }
    int ans = min_value();

    for (int i = k + 1; i <= n; i++) {
        add(vec[i]);
        rem();
        ans ^= min_value();
    }

    cout << ans << endl;
    
    return 0;
}