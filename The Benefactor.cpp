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


vector<pair<ll ,ll >> adj[50010];
pair<ll,ll> bfs(ll x , ll n)
{
    bool vis[n+1]={false};
    ll dist[n+1]={0};

    queue<int> q;
    q.push(x);

    vis[x] = true;

    while(!q.empty())
    {
        auto k=q.front();

        q.pop();

        for(ll i=0;i<adj[k].size();i++)
        {
            ll edge = adj[k][i].ff;
            ll d = adj[k][i].ss;

            if(vis[edge] == false)
            {
                dist[edge] = dist[k]+d;
                q.push(edge);
                vis[edge] = true;
            }
        }
    }

    int node , maxd=-1;

    for(ll i=1;i<=n;i++)
    {
        if(maxd<dist[i]){
            maxd=dist[i];
            node=i;
        }
    }

    return {node, maxd};


}
void cook_here()
{
    ll n;
    cin>>n;

    for(ll i=0;i<=n;i++) adj[i].clear();

        ll x,y,d;

    for(int i=0;i<=n-2;i++){
        cin>>x>>y>>d;
        adj[x].pb({y,d});
        adj[y].pb({x,d});


    }
    
    pair<ll,ll> a1=bfs(1,n);
    pair<ll,ll> a2=bfs(a1.ff,n);

    cout<<a2.ss<<endl;

    
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
    cin>>t;
    while(t--){
        cook_here();
    }
    return 0;
    


}
