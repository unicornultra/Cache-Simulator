#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;typedef vector<ll> vi;typedef pair<ll,ll> pii;typedef vector<vector<ll>> vii;
#define ff first
#define ss second
#define all(v) begin(v),end(v)
#define in(x...) ll x;inpp(x);
#define inv(v,n) vector<ll> v(n);for(ll i=0;i<n;i++)cin>>v[i];debug(v)
#define inv1(v,n) vector<ll> v(n+1);for(ll i=1;i<=n;i++)cin>>v[i];debug(v)
void inpp(auto & x){cin>>x;};void inpp(auto&x,auto&...y){inpp(x);inpp(y...);}
#define fal(x,y) for(auto x : y)
#define pr(x,y) (y.find(x)!=y.end())
#ifdef CODER
    #include<bits/debugger.h>
#else
    #define cl()
    #define graph(x,y)
    #define debug(x...)
#endif

#define int long long int

void solve(){
    cout<<"Hello"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<setprecision(12)<<fixed;
    int t=1,TestCase=0;
    while(t--){
        TestCase++;debug(TestCase)
            solve();
        cl()
    }
return 0;
}
//!                ______          ______                  !//
//!  \\\    ///   ///  \\\      |||      |||  |||     |||  !//
//!   \\\  ///   ///    \\\     |||           |||_____|||  !//
//!    \\\///   ///______\\\    |||_______    |||_____|||  !//
//!     \///   ///________\\\            |||  |||_____|||  !//
//!     ///   ///          \\\           |||  |||     |||  !//
//!    ///   ///            \\\ |||______|||  |||     |||  !//