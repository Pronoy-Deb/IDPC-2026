#include <bits/stdc++.h>
using namespace std;

int check(long long a) {
    int ans = 0;

    for (long long i = 2; i * i <= a; i++) {
        int count = 0;
        while (a % i == 0) {
            count++;
            a /= i;
        }
        if (count % 2 != 0) {
            ans++;
        }
    }

    if (a > 1) {
        ans++;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    long long total = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        total += check(x);
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}