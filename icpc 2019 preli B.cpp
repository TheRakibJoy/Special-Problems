//starting with the name of almighty ALLAH
///Author - RakibJoy
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define dbg(x) cerr<<x<<endl;
#define mp(x,y) make_pair(x,y)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define tst int t;cin>>t;while(t--)
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rj ios::sync_with_stdio(false);cin.tie(0);
#define rvs(v) reverse(v.begin(),v.end());
#define F first
#define S second
#define MOD 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define fr(i,a,b) for(ll i=a;i<=b;i++)
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v) for(auto &it:v)cin>>it;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ld long double
#define nl '\n'
const int N=1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
pair<int, int>,
     null_type,
     less<pair<int, int>>,
     rb_tree_tag,
     tree_order_statistics_node_update> ordered_set;
vector<int>par;
ordered_set os[100005];
void init(int n)
{
    par.assign(n+1,0);
    for(int i=1; i<=n; i++)
        par[i]=i,os[i].clear();
}
int get_parent(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=get_parent(par[n]);
}
void union_set(int x,int y)
{
    x=get_parent(x);
    y=get_parent(y);
    if(x!=y)
    {
        if(os[x].size()<os[y].size())
            swap(x,y);
        par[y]=x;
        for(auto it:os[y])
        {
            os[x].insert(it);
        }
        os[y].clear();
    }
}
void solve()
{
    int a,b;
    scanf("%d%d",&a,&b);
    init(a);
    int cnt=0;
    fr(i,1,b)
    {
        int t;
        scanf("%d",&t);
        if(t==0)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            union_set(x,y);
        }
        else if(t==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int p=get_parent(x);
            os[p].insert({y,cnt++});
        }
        else
        {
            int x,l,r;
            scanf("%d%d%d",&x,&l,&r);
            x=get_parent(x);
            printf("%d\n",os[x].order_of_key ({r,INT_MAX})-os[x].order_of_key({l-1,INT_MAX}));
        }
    }
}
int main()
{

    ll t;scanf("%d",&t);fr(i,1,t) printf("Case %d:\n",i),solve();
    return 0;
}
