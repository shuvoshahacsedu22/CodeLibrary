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
#define root 1
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
int N,T;
int dist[205];
int dis[205];
vector<int> ss;
vector<pii> g[205];
void bellmanford(int source)
{
        REP(i,N) dist[i]=INF;
        int V=N;
        dist[source] = 0;
        REP(i,V-1)
// relax all E edges V-1 times
        REP(u,V)
// these two loops = O(E), overall O(VE)
        REP(j,g[u].size())
        {
        pii v = g[u][j];
// record SP spanning here if needed
        if(dist[u]!=INF)
        dist[v.second] = min(dist[v.second], dist[u] + v.first);
// relax
        }
        REP(i,205) dis[i]=dist[i];
        REP(u,V)
        REP(j,g[u].size())
        {
        pii v = g[u][j];
// record SP spanning here if needed
        if(dist[u]!= INF)
        dist[v.second] = min(dist[v.second],dist[u] + v.first);
// relax
        }
//    REP(i,N)
//    {
//    cout<<0<<"---->"<<i<<": "<<dist[i]<<endl;
//
//    }
       queue<int> q;
       bool vis[205];
       REP(i,205) vis[i]=false;
       REP(i,205) if(dis[i]!=dist[i]) q.push(i);
       while(!q.empty())
       {
         int u=q.front();
         q.pop();
         vis[u]=true;
         REP(i,g[u].size())
         {
           int k=g[u][i].second;
          if(vis[k]==false)
          {
          vis[k]=true;
          q.push(k);
          }
         }
       }
    REP(i,ss.size())
    if(dist[ss[i]]==INF || dist[ss[i]]<3 || vis[ss[i]]) cout<<"?"<<endl;
    else cout<<dist[ss[i]]<<endl;
    ss.clear();
    REP(i,N) dist[i]=dis[i]=INF;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,u,v,w,n,m,source;
    t=0;
    while(scanf("%d",&n)==1)
    {
        t++;
        REP(i,n) cin>>dist[i];
        N=n;
        cin>>m;
        REP(i,m)
        {
            cin>>u>>v;
            u--;
            v--;
            g[u].pb(mp((dist[v]-dist[u])*(dist[v]-dist[u])*(dist[v]-dist[u]),v));
            //g[v].push_back(make_pair((int)pow(dist[u]-dist[v],3),u));
        }
        int q,a;
        cin>>q;
        cout<<"Set #"<<t<<endl;
        REP(i,q)
        {
         cin>>a;
         ss.push_back(a-1);
         }
        if(ss.size()!=0)
        bellmanford(0);
        REP(i,N) g[i].clear();
        ss.clear();
    }
    return 0;
}
