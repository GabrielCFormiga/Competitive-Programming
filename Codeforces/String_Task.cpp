/**
* @file String_Task.cpp
* https://codeforces.com/problemset/problem/118/A
*
* Created on 2025-03-01 at 01:26:07
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

bool isVogal(char c) {
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'y' || c == 'Y'); 
}

int main() { _
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (!isVogal(str[i])) {
            cout << '.';
            if (str[i] >= 'A' && str[i] <= 'Z') cout << char(str[i] - 'A' + 'a'); 
            else cout << str[i];
        }
    }
    cout << endl;
    
    return 0;
}