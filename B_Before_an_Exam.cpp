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
    ll days,hours;
 
    cin>>days>>hours;
       ll n = days;
    vector<pair<int,int>> store(n);
    ll mini = 0;
    ll maxi = 0;
    vector<int> ans(n);
    fr(days){
        int a,b;
        cin>>a>>b;
        mini +=a;
        maxi +=b;
        store[i] = {a,b};
        ans[i] = a;
    }
    if(hours>=mini && hours<=maxi){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
        return;
    }

    ll left = hours-mini;
    for(int i=0;i<n;i++){
        if(left){
            if(left>(store[i].second-store[i].first)){
                ans[i] = store[i].second;
                left -= (store[i].second-store[i].first);
            }else{
                ans[i] += left;
                left =0;
                break;
            }
        }else{
            break;
        }
    }
    fr(n) cout<<ans[i]<<" ";
    nl;
}

int main(){
    fast;
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}