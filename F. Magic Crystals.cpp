#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7, N = 2e5 + 5;
long long fac[N], inv[N], finv[N];

void pre() {
    fac[0] = fac[1] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = (fac[i - 1] * i) % M;
        inv[i] = inv[M % i] * (M - M / i) % M;
        finv[i] = (inv[i] * finv[i - 1]) % M;
    }
}

long long ncr(long long n, long long r) {
    if (r > n || r < 0) return 0;
    if (!r || n == r) return 1;
    if (r == 1) return n;
    return ((fac[n] * finv[r]) % M * finv[n - r]) % M;
}

void solve() {
    long long n, k;
    cin >> n >> k;

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        sum = (sum + a) % M;
    }

    long long ans = (sum * ncr(n - 1, k - 1)) % M;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}