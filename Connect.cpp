#include <bits/stdc++.h>
using namespace std;

#define codephillic__ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

typedef long long ll;
#define mod (int) 998244353
long long MOD=1e9+7;
// Big two primes
#define X 1001100011100001111ll
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)

#define pb push_back
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define fill__(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define ff first
#define ss second
#define endl "\n"
#define pi 3.1415926536
#define pii pair<int, int>
#define vii vector<pi>
const int MAXN = (int)((1e5) + 100);

const int N=50*50*10;
string s[N];
int turn=0,n;
bool vis[55][55];
vector<pair<ll , ll>> adj[2];
void dfs( ll i , ll j)
{
    if(i<0 || i>=n || j<0 || j>=n)
        return;

    if(vis[i][j] == true)
        return ;
    vis[i][j] = true;

    if(s[i][j]=='1')
        return ;

    adj[turn].pb({i,j});

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);


}
void cook_here()
{
    //ll n;
    cin >> n;
    ll a,b;
    cin>>a>>b;
    ll x,y;
    cin>>x>>y;
    a-- , b-- , x-- , y--;
    //vector<vector<ll>> v;

    for(ll i=0;i<n;i++){
        cin>>s[i];
    }

    memset(vis , false , sizeof(vis));



    /*for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            
        }
    }
*/  
    dfs(a,b);

    turn=1;
    memset(vis , false , sizeof(vis));
    dfs(x,y);

    ll ans=INT_MAX;

    for(auto i: adj[0]){
        for(auto j:adj[1])
        {
            //cout<<ans<<endl;
            ans=min(ans , (j.ff-i.ff)*(j.ff-i.ff) + (j.ss-i.ss)*(j.ss-i.ss));
        }
    }


    cout<<ans<<endl;



}
int32_t main() {
/*
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
*/
    codephillic__;
//srand(time(NULL));
    ll t=1;
    //cin>>t;
    while(t--){
        cook_here();
    }
    return 0;
    


}
