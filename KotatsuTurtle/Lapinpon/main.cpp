/////////////////////////////////////////////////////////
//
//  c/temp.cpp file
//  Last Updated: 2018-10-23 ...Maybe
//
//    I hope you adding this code to the setting file
//    alias g++='g++ -std=c++1y -DDEBUG_LOCAL'
//
/////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

//#define int long long

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REAP(i,0,n)
#define REAP(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REAP,_REP,)(__VA_ARGS__)

#define _REPR(i,n) REAPR(i,n,0)
#define REAPR(i,a,b) for(int i=int(a-1);i>=int(b);--i)
#define REPR(...) _overload3(__VA_ARGS__,REAPR,_REPR,)(__VA_ARGS__)

#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()

#define coutALL(a) {int loop_coutALL=0;for(auto e:a) cout<<(loop_coutALL++?" ":"")<<e; cout<<endl;}

#define coutYN(a) cout<<((a)?"YES":"NO")<<endl;
#define coutYn(a) cout<<((a)?"Yes":"No")<<endl;
#define coutyn(a) cout<<((a)?"yes":"no")<<endl;

#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)

const int INF=1145141919;
//const long long INF=114514191911451419;
const int MOD=(int)1e9+7;
const double EPS=1e-12;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
//const int dx8[]={-1,-1,-1,0,1,1,1,0},dy8[]={-1,0,1,1,1,0,-1,-1};

using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;

typedef long long ll;

template<typename T> istream &operator >> (istream &is, vector<T> &v){for(T &x:v) is>>x;return is;}
template<typename T> ostream &operator << (ostream &os, vector<T> &v){int i=0;for(T &x:v) os<<(i++?" ":"")<<x;return os;}

ll rev(ll n){ll x=0;for(;n>0;){x=x*10+n%10;n/=10;}return x;}

ll upper(ll n,ll m){return (n+m-1)/m;};
ll rounding(ll n){return (long double)n+0.5;};

bool inG(ll x,ll n){return 0<=x && x<n;}
bool outG(ll x,ll n){return x<0 || n<=x;}

inline int qp(int a,ll b){if(!b)return 1;int ans=1;do{if(b&1)ans=1ll*ans*a;a=1ll*a*a;}while(b>>=1);return ans;}
inline int qp(int a,ll b,int mo){if(!b)return 1;int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

inline ll fac(ll k,ll n){ll a=1;for(int i=0;i<n;i++)a*=k--;return a;}
inline ll fac(ll k,ll n,int mo){ll a=1;for(int i=0;i<n;i++)a*=k--,a%=mo;return a;}

inline int dsum(ll n){int a=0;for(;n;n/=10)a+=n%10;return a;}

struct Arithmetic{Arithmetic(){cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);}};

//#define DEBUG_LOCAL

#ifdef DEBUG_LOCAL
template<typename T> void deb(T a){cerr<<"deb: "<<a<<"です"<<endl;}
#define debl {cerr<<"debug: "<<__LINE__<<"行目だ"<<endl;}
void what_cr(){cout<<__GCC_ATOMIC_CHAR16_T_LOCK_FREE<<" ←？"<<endl;}
//ori_func S

//ori_func E
#else
template<typename T>void deb(T a){}
#define debl
void what_cr(){}void t_t(){}
#endif

const int dx9[]={-1,-1,-1,0,1,1,1,0,0},dy9[]={-1,0,1,1,1,0,-1,-1,0};

#define MAX_HW 1000000

int d[MAX_HW];
vector <pii> g[MAX_HW];
void dijk(int V,int s){

  priority_queue <pii,vector<pii>,greater<pii> > que;
  fill(d,d+V,INF);

  d[s]=0;

  que.push(pii(0,s));

  for(;!que.empty();){

    pii p=que.top(); que.pop();
    int v=p.se;

    if (d[v]<p.fi) continue;

    for(int i=0;i<(int)g[v].size();i++){

      pii e=g[v][i]; //fiが場所、seがコスト

      if(d[e.fi]>d[v]+e.se){

	       d[e.fi]=d[v]+e.se;
	       que.push(pii(d[e.fi],e.fi));

      }
    }
  }
}

vs make_map(int h,int w){

  string s(w,0);

  vs make_c(h,s);

  REP(i,h) REP(j,w){

    if(i+j == 0) make_c[i][j]='g';
    else if(i == h-1 && j == w-1) make_c[i][j]='s';
    else make_c[i][j]='#';

  }

  return make_c;

}

signed main(){

  Arithmetic Exception;

  int h,w,a,b;
  cin>>h>>w>>a>>b;

  vs s(h);

  cin>>s;

  // s=make_map(h,w);

  int st=-1,go=-1;

  REP(i,h) REP(j,w){

    bool isbom=false;

    if(s[i][j] == 's') st=i*w+j;
    if(s[i][j] == 'g') go=i*w+j;

    REP(dir,9){

      int y=i+dy9[dir],x=j+dx9[dir];

      if(outG(y,h) || outG(x,w)) continue;

      if(s[y][x] == '*') isbom=true;

    }

    REP(dir,4){

      int y=i+dy[dir],x=j+dx[dir];

      if(outG(y,h) || outG(x,w)) continue;

      if(s[y][x] != '#') g[i*w+j].pb(mp(y*w+x,a));
      if(!isbom){

        g[i*w+j].pb(mp(y*w+x,a+b));

        int y_=y,x_=x;

        if(dy[dir]) x_+=dy[dir];
        else y_+=dx[dir];

        if(!(outG(y_,h) || outG(x_,w))) g[i*w+j].pb(mp(y_*w+x_,a*2+b));


        y_=y,x_=x;

        if(dy[dir]) x_-=dy[dir];
        else y_-=dx[dir];

        if(!(outG(y_,h) || outG(x_,w))) g[i*w+j].pb(mp(y_*w+x_,a*2+b));

      }

    }

  }

  dijk(h*w,st);

  if(d[go] == INF) cout<<"INF"<<endl;
  else cout<<d[go]<<endl;

  return 0;

}
