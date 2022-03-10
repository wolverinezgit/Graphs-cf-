
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
m=n-1;
vector<vector<ll>> G(n+1);
ll i;
for(i=0;i<m;i++)
{
    ll xx,yy;
    cin>>xx>>yy;
    G[xx].pb(yy);
    G[yy].pb(xx);

}
vector<ll> seq(n);
map<ll,ll> seqm;

for(i=0;i<n;i++)
{
    cin>>seq[i];
seqm[seq[i]]=i;
}

set<pair<ll,ll>> s1;
vector<ll> vis(n+1,0);
bool ok=true;
queue<ll> q;
vector<ll> ans;
vis[1]=1;
q.push(1);
ll j=0;
while(!(q.empty())&&ok)
{
    ll sz=q.size();
    for(i=0;i<sz;i++)
    {



if(q.front()!=seq[j])
{
   ok=0;
   break;
}
q.pop();
priority_queue<pair<ll,ll>> pq;
for(auto z:G[seq[j]])
{
    if(vis[z]==0)
    {
        pq.push({-seqm[z],z});   

        vis[z]=1;
    }
    }
    while(!pq.empty())
    {
        q.push((pq.top()).second);
        pq.pop();
    }
    j++;
}
}

if(ok)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;

return 0;
}

