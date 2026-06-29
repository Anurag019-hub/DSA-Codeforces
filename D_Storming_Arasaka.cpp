#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1000000007
#define pb push_back
#define is insert
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rfr(n) for(int i=n-1;i>=0;i--)
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define fr(n) for(long long i=0;i<n;i++)
#define nesfr(x,y) for(long long i=0;i<x;i++)for(long long j=0;j<y;j++)
#define rep(i,a,b) for(long long i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
#define nl cout << "\n"
const unsigned int M = 1000000007;
const int  N = 2e5 + 5 ;

vector<pair<ll, ll>> getPrimeFactors(ll n) {
    vector<pair<ll, ll>> factors;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll count = 0ll;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

void solve() {
    ll n;
    cin >> n;

    vector<pair<ll,ll>> factors = getPrimeFactors(n);
    ll total_layers = 0;
    for (auto& f : factors) {
        total_layers += f.second;
    }
    ll first_layer_count = factors.size();
    ll result = total_layers + first_layer_count;

    cout << result-1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 
    while (t--) {
        solve(); 
    }

    return 0;
}