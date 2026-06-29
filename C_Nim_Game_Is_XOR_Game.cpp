#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long total_xor = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_xor ^= a[i];
    }

    if (total_xor == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1; 

    for (int bit = 0; bit < 30; bit++) {
        vector<long long> next_dp(n + 1, 0);

        int count_ones = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] >> bit) & 1) {
                count_ones++;
            }
        }
        int count_zeros = n - count_ones;
    }
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