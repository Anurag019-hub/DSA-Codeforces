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
vector<ll> two_po;
void solve() {
    long long n, k;
    cin >> n >> k;
    
    long long total_popcount = 0;
    long long current_bit_value = 1;
    
    while (n > 0 && current_bit_value <= n) {
        long long max_bits_we_can_afford = n / current_bit_value;
        long long take = min(k, max_bits_we_can_afford);
        total_popcount += take;
        n -= take * current_bit_value;
        current_bit_value *= 2;
    }
    
    cout << total_popcount << "\n";
}

int main(){
    fast;
    ll t=1;
    cin>>t;
    two_po.push_back(1);
    for(int i=1;i<32;i++){
        two_po.push_back(two_po[i-1]*2);
    }
    while(t--){
        solve();
    }
    return 0;
}