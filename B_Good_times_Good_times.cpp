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

vector<ll> good_numbers;

bool is_good(ll n) {
    int mask = 0;
    while (n > 0) {
        mask |= (1 << (n % 10));
        n /= 10;
    }
    return __builtin_popcount(mask) <= 2;
}

void precompute() {
    set<ll> unique_goods;
    for (int d1 = 0; d1 <= 9; ++d1) {
        for (int d2 = 0; d2 <= 9; ++d2) {
            queue<ll> q;
            if (d1 != 0) q.push(d1);
            if (d2 != 0 && d1 != d2) q.push(d2);
            
            while (!q.empty()) {
                ll curr = q.front();
                q.pop();
                
                if (curr >= 2 && curr <= 1000000000LL) {
                    unique_goods.insert(curr);
                }
                
                if (curr * 10 > 1000000000LL) continue;
                
                q.push(curr * 10 + d1);
                if (d1 != d2) {
                    q.push(curr * 10 + d2);
                }
            }
        }
    }
    
    for (ll val : unique_goods) {
        good_numbers.push_back(val);
    }
}

void solve() {
    ll x;
    cin >> x;
    for (ll y : good_numbers) {
        ll product = x * y;
        if (is_good(product)) {
            cout << y << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}