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
    ll n;cin>>n;
    string s;cin>>s;
    ll one =0;
    ll zer=0;
    vi arr(n);
    for(int i=0;i<n;i++){
        if(s[i]=='0') zer++;
        else one++;
        arr[i] = zer-one;
    }

    //unordered map having val and its first occurance
    
    unordered_map<ll,ll> store;
    store[0] = -1;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(store.find(arr[i])!=store.end()){
            ans = max(ans,i-store[arr[i]]);
        }else{
            store[arr[i]] = i;
        }
    }
cout<<ans<<"\n";
}

int main(){
    fast;
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}