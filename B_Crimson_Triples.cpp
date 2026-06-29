#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
typedef long long int ll;
typedef vector<ll> vi;

const int N = 2e5 + 5;
vi sk(N, 0);

// Precompute the actual number of divisors for each number up to max N
void precompute_divisors() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            sk[j]++;
        }
    }
}

void solve() {
    int n; 
    cin >> n;   
    
    vi gcd_pairs(n + 1, 0);
    ll total_crimson_triples = 0;
    
    for (int g = n; g >= 1; g--) {
        ll multiples = n / g;
        gcd_pairs[g] = multiples * multiples; 
        
        for (int m = 2 * g; m <= n; m += g) {
            gcd_pairs[g] -= gcd_pairs[m];
        }
        
        total_crimson_triples += gcd_pairs[g] * sk[g];
    }
    
    cout << total_crimson_triples << "\n";
}

int main() {
    fast;
    precompute_divisors();
    
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}