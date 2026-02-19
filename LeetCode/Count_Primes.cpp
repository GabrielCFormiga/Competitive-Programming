class Solution {
public:
    int countPrimes(int n) {
        int ret = 0;
        vector<bool> isprime(n, true);
        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                ret++;
                for (long long j = 1ll * i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }
        return ret;
    }
};