
#include <bits/stdc++.h> 
using namespace std;
 #define ff first
#define ss second
#define ll long long
#define pb push_back
  
int main()
{
 
 
  ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
 

ll t;

ll n;
cin>>n;

ll m;
cin>>m;
vector<vector<ll>> G(n+1);
ll i;
for(i=0;i<m;i++)
{
    ll xx,yy;
    cin>>xx>>yy;
    G[xx].pb(yy);
    G[yy].pb(xx);

}
priority_queue<ll> pq;
vector<ll> vis(n+1,0);
vector<ll> ans;
vis[1]=1;
pq.push(-1);
while(!pq.empty())
{
    ll sz=pq.size();
    for(i=0;i<sz;i++)
    {
ll xx=(pq.top());

ans.pb(xx);
pq.pop();
xx=-xx;
for(auto z:G[xx])
{
    if(vis[z]==0)
    {
        pq.push(-z);   

        vis[z]=1;
    }
    }
}
}

for(auto x:ans)
    cout<<-x<<" ";

return 0;
}

