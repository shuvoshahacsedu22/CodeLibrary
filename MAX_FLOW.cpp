
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <fstream>
#include <limits>
#define ALPHABET_SIZE 26
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define REP(i,n)    for(int i=0;i<n;i++)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define INF 1e9
#define MAX_V 100

int s,t,f,mf,resi[MAX_V][MAX_V];
int p[MAX_V],dist[MAX_V];
vector<int> g[MAX_V];


void augment(int v,int minEdge){

        if(v==s) { f=minEdge;return;}
        else if(p[v]!=-1) {augment(p[v],min(minEdge,resi[p[v]][v]));}
            resi[v][p[v]]+=f,resi[p[v]][v]-=f;

}



int maxFlow(){
    mf=0;
    while(1){


        REP(i,MAX_V) p[i]=-1,dist[i]=INF;
        f=0;
        dist[s]=0;
        queue<int> q;
        q.push(s);

        while(!q.empty()){

        int u=q.front();q.pop();
        if(u==t) break;//reached the sync

        for(int i=0;i<g[u].size();i++){

                    int v=g[u][i];
                    if(resi[u][v]>0 && dist[v]==INF){

                        dist[v]=dist[u]+1;
                        p[v]=u;
                        q.push(v);

                    }

            }

        }

        augment(t,INF);
        if(f==0) break;
        mf+=f;
    }

return mf;
}


int main(){

    //freopen("in.txt","r",stdin);
    int n,m,w,u,v;
    cin>>n>>m;
    REP(i,m){

        cin>>u>>v>>w;
        g[u].pb(v);
        g[v].pb(u);
        resi[u][v]=w;
        resi[v][u]=0;

    }
    cout<<maxFlow()<<endl;
    return 0;
}
