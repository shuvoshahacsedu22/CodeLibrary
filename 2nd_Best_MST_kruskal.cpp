#include<bits/stdc++.h>
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
#define MX 115
#define INF 10000002
#define debug(m) printf("%d",m);
#define mp make_pair
typedef pair<int,int> pii;
typedef pair< int, pair<int,int> > piii;

int N;
int dis[MX];
bool vis[MX];
int pr[MX];
vector< piii > adjList;
vector<int> G;
int root(int r)
{
    return (pr[r]==r)?r:root(pr[r]);
}

int MST_kruskal()
{
    sort(adjList.begin(),adjList.end());
    for(int i=0; i<MX; i++) pr[i]=i;
    int total_cost=0;
    int cnt_tree_edge=0;
    for(int i=0; i<adjList.size(); i++)
    {
        int u=root(adjList[i].second.first);
        int v=root(adjList[i].second.second);
        if(u!=v)
        {
            //union of u and v by setting their root same
            pr[u]=v;
            cnt_tree_edge++;
            total_cost+=adjList[i].first;
            G.pb(i);
            //g[adjList[i].second.first].pb(mp(adjList[i].first,adjList[i].second.second));
            //g[adjList[i].second.second].pb(mp(adjList[i].first,adjList[i].second.first));
            if(cnt_tree_edge==N-1) break;
        }
    }
    if(cnt_tree_edge!=N-1) return -1;
    return total_cost;
}
int secondMST(int jj)
{
    for(int i=0; i<MX; i++) pr[i]=i;
    int total_cost=0;
    int cnt_tree_edge=0;
    for(int i=0; i<adjList.size(); i++)
    {
        if(i==jj)continue;
        int u=root(adjList[i].second.first);
        int v=root(adjList[i].second.second);
        if(u!=v)
            {
            //union of u and v by setting their root same
            pr[u]=v;
            cnt_tree_edge++;
            total_cost+=adjList[i].first;
            //g[adjList[i].second.first].pb(mp(adjList[i].first,adjList[i].second.second));
            //g[adjList[i].second.second].pb(mp(adjList[i].first,adjList[i].second.first));
            if(cnt_tree_edge==N-1) break;
            }
    }
    if(cnt_tree_edge!=N-1) return -1;
    return total_cost;
}

/*
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
}*/
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t=0,u,v,k,w,n,m,q,source;
    cin>>t;
    REP(i,t)
    {
     cin>>n>>m;
     N=n;
     REP(i,m)
     {
     cin>>u>>v>>w;
     adjList.pb(mp(w,mp(u,v)));
     }
     cout<<"Case #"<<i+1<<" : ";
     int totalcost=MST_kruskal();
     if(totalcost==-1) cout<<"No way"<<endl;
     else if(m==N-1) cout<<"No second way"<<endl;
     else{
     int mim=INF;
     REP(l,N-1)
     {
     int k=secondMST(G[l]);
     if(k!=-1) mim = min(mim,k);
     }
     cout<<mim<<endl;
     }
     adjList.clear();
     G.clear();
     //g.clear();
    }
    return 0;
}
