#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

namespace nf{
#define N 210
#define M 3000010
#define INF (1<<30)
  int le[N],pe[M],ecnt,data[M],ev[M];
  void addEdge(int u,int v,int cap){
    pe[ecnt]=le[u];
    ev[ecnt]=v;
    data[ecnt]=cap;
    le[u]=ecnt++;
    
    pe[ecnt]=le[v];
    ev[ecnt]=u;
    data[ecnt]=0;
    le[v]=ecnt++;
  }
  int S,T;
  void init(int s,int t){
    memset(le,-1,sizeof(le));
    ecnt=0;
    S=s,T=t;
  }
  int dist[N],q[N],front,rear;
  int bfs(){
    memset(dist,-1,sizeof(dist));
    front=rear=0;
    q[front]=S;
    dist[S]=0;
    while(front<=rear){
      int u=q[front++];
      for(int i=le[u]; i!=-1; i=pe[i]){
	if(data[i] && dist[ev[i]]==-1){
	  dist[ev[i]]=dist[u]+1;
	  q[++rear]=ev[i];
	}
      }
    }
    return dist[T]!=-1;
  }
  int dfscnt=0,cur[N],mark[N]={0},cnt;
  int dfs(int u,int a){
    cnt++;
    if(u==T || a==0)return a;
    int ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt,cur[u]=le[u];}
    for(int &i=cur[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]!=dist[u]+1)continue;
      f=dfs(v,min(a,data[i]));
      data[i]-=f;
      data[i^1]+=f;
      a-=f;
      ret+=f;
    }
    return ret;
  }
  int maxFlow(){
    int ret=0;
    dfscnt=0;
    memset(mark,0,sizeof(mark));
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}

using namespace nf;

int n,m;
bool check(){
  REP(i,1,n){
    addEdge(S,i,1);
    addEdge(n+i,T,1);
  }
  return maxFlow()==n;
}

char g[60][60];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  init(0,n*4+1);
  REP(i,1,n){
    addEdge(i,n*2+i,m);
    addEdge(n*2+n+i,n+i,m);
    scanf("%s",g[i]+1);
    REP(j,1,n){
      if(g[i][j]=='Y')
        addEdge(i,n+j,1);
      else
        addEdge(n*2+i,n*2+n+j,1);
    }
  }
  int ans=0;
  while(check())ans++;
  printf("%d\n",ans);
  return 0;
}
