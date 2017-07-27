#include<bits/stdc++.h>
using namespace std;
#define for(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main()
{
    int t;
    cin>>t;
    for(k,t)
    {
        if(k!=0) cout<<endl;
      int n,m,a,b;
      cin>>n>>m;
      vector<int> adj[n];
      int vis[n];
      for(i,n) vis[i]=0;
      for(i,m) {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }

    queue<int> Q;
    Q.push(0);
    vis[0]=1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(i,adj[u].size())
            if(vis[adj[u][i]]==0)
        {
            int v = adj[u][i];
            vis[v]= vis[u]+1;
            Q.push(v);
        }
    }


      for(i,n)
      {
          if(i==0)continue;
          printf("%d\n",vis[i]-1);
      }

    }

    return 0;
}
