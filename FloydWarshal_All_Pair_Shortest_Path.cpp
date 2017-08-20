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
int  g[100][100];

void floydWarshall(int n){

  //For all edges (i, j), G[i][j] = length of the edge, infinity otherwise
  //G[i][i] = 0 for all i
  for(int k=0; k<n; k++)  {
    for(int i=0; i<n; i++)  {
      for(int j=0; j<n; j++)  {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}
int main()
{
    int t,n,m,u,v,w;
    cin>>t;
    REP(i,t){
    cin>>n>>m;
    REP(i,n)REP(j,n) g[i][j]=INF;
    REP(i,m)
    {
        cin>>u>>v>>w;
        g[u][u]=0;
        g[v][v]=0;
        g[u][v] = w;
        g[v][u] = w;
    }
    floydWarshall(n);
    REP(i,n)
    REP(j,n)
    {
    cout<<i<<"----"<<j<<"="<<g[i][j]<<endl;
    }
    }
    return 0;
}
