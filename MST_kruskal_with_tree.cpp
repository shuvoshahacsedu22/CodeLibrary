#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<ctime>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define AIN(a, b, c) assert(b <= a && a <= c)
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
//#define root 1
#define lft 2*idx
#define mp make_pair
#define rgt 2*idx+1
#define cllft lft,st,mid,s,e
#define inf (1<<29)
#define MX 10000
#define INF 10000002
#define debug(m) printf("%d",m);
#define mp make_pair
typedef pair<int,int> pii;
typedef pair< int, pair<int,int> > piii;

int dis[MX];
bool vis[MX];
int pr[MX];
vector< piii > adjList;
vector<pii> g[MX];
int root(int r)
{
    return (pr[r]==r)?r:root(pr[r]);
}

int MST_kruskal(int n)
{
    sort(adjList.begin(),adjList.end());
    for(int i=0; i<=n; i++) pr[i]=i;

    int cnt_tree_edge=0,total_cost=0;

    for(int i=0; i<adjList.size(); i++)
    {
        int u=root(adjList[i].second.first);
        int v=root(adjList[i].second.second);
        if(u!=v)
        {//union of u and v by setting their root same
            pr[u]=v;
            cnt_tree_edge++;
            total_cost+=adjList[i].first;
            g[adjList[i].second.first].pb(mp(adjList[i].first,adjList[i].second.second));
            g[adjList[i].second.second].pb(mp(adjList[i].first,adjList[i].second.first));
            if(cnt_tree_edge==n-1) break; //it can not be a loop

        }
    }
    return total_cost;
}
void dfs(int source)
{
  vis[source]=true;
  REP(i,g[source].size())
  {
   int v=g[source][i].second;
   if(!vis[v])
   {
   vis[v]=true;
   dis[v]=max(dis[source],g[source][i].first);
   dfs(v);
   }
  }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,u,v,w,n,m,source;
    cin>>t;
    REP(i,t)
    {
        cin>>n;
        cin>>m;
        REP(i,m)
        {
            cin>>u>>v>>w;
            adjList.pb(mp(w,mp(u,v)));
        }
        int source;
        cin>>source;
        int k=MST_kruskal(n);
        dfs(source);
        cout<<"Case "<<i+1<<":"<<endl;
        REP(i,n) if(vis[i])cout<<dis[i]<<endl;else cout<<"Impossible"<<endl;
        REP(i,n) vis[i]=false,dis[i]=0,g[i].clear();
        adjList.clear();
    }
    return 0;
}
