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

void solve(){
    // your per-test-case code here
    ll n;
    cin>>n;
    vi arr(n);
    fr(n) cin>>arr[i];
    unordered_map<int,int> present;
    vi rem;
    for(int i=0;i<n;i++){
        if(arr[i]<n) present[arr[i]]++;
        else rem.push_back(arr[i]);
    }
    if(rem.size()>0) sort(rem.begin(),rem.end());
    ll ans =0;
    ll pos = 0;
    for(int i=0;i<n;i++){
        if(present[i]<=0){
            if(pos>=rem.size() ){
                break;
            }else if((rem[pos])<=2*i){
                i-- ;
                ans--;
            }
            pos++;
        }
        ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    fast;
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}