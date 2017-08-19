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
int dist[MX];
vector<pii> g[MX];
int dij(int source)
{
    REP(i,N) dist[i]=INF;
    priority_queue<pii,vector<pii>,greater<pii> > pq;//this sorts the queue in ascending order of weight/path
    dist[source]=0;
    pq.push(make_pair(0,source));
    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int u = top.second;//source node
        int d = top.first;//distance of existing node from source node that is 0
        if(d > dist[u]) continue;
        else
        REP(i,g[u].size())
        {
         pii k=g[u][i];
         if(d+k.first<dist[k.second])
         {
         dist[k.second]=d+k.first;
         pq.push(make_pair(dist[k.second],k.first));
         }
        }

    }
REP(i,N) cout<<"Distance from source 0->"<<i<<": "<<dist[i]<<endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,u,v,w,n,m,source;
    cin>>t;
    REP(i,t)
    {
      cin>>n>>m;
      N=n;
      REP(i,m)
      {
      cin>>u>>v>>w;
      g[u].push_back(make_pair(w,v));
      g[v].push_back(make_pair(w,u));
      }
      dij(0);
    }
    return 0;
}
