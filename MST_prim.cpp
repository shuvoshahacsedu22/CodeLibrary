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

bool marked[MX];
vector <pii> g[MX];

int prim(int source)
{
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    int v;
    int minimumCost = 0;
    pii p;
    Q.push(make_pair(0, source));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        source = p.second;
        // Checking for cycle
        if(marked[source] == true)
            continue;
        minimumCost += p.first;
        marked[source] = true;
        REP(i,g[source].size())
        {
            v = g[source][i].second;
            if(marked[v] == false)
                Q.push(g[source][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int t,n,m,source,u,w,v,minimumCost;
    cin>>t;
    REP(i,t){
    cin>>n>>m;
    REP(i,m)
    {
        cin>>u>>v>>w;
        g[u].push_back(make_pair(w, v));
        g[v].push_back(make_pair(w, u));
    }
    cin>>source;
    // Selecting 1 as the starting node
    minimumCost = prim(source);
    cout << minimumCost << endl;

    REP(i,n) g[i].clear(),marked[i]=false;
    }
    return 0;
}
