//starting with the name of almighty ALLAH
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll long long int
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
const int N = 1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
string s[100];
int a, b;
bool vis[100][100];
void dfs(int x, int y)
{
    if (x >= a || x < 1 || y >= b || y < 1) return;
    if (vis[x][y]) return;
    vis[x][y] = 1;
    if (!(s[x][y - 1] == 'R' || s[x][y - 1] == 'B'))
        dfs(x + 1, y);
    if (!(s[x - 1][y - 1] == 'R' || s[x - 1][y - 1] == 'B'))
        dfs(x - 1, y);

    if (!(s[x - 1][y] == 'D' || s[x - 1][y] == 'B'))
        dfs(x, y + 1);


    if (!(s[x - 1][y - 1] == 'D' || s[x - 1][y - 1] == 'B'))
        dfs(x, y - 1);

}
void solve()
{
    cin >> a >> b;
    for (int i = 0; i < a; i++) cin >> s[i];
    for (int i = 0; i < b - 1; i++)
    {
        if (s[0][i] == 'R' || s[0][i] == 'B') continue;
        dfs(1, i + 1);
    }
    int cnt = 0;
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j < b; j++)
        {
            if (vis[i][j]) cnt++;
            vis[i][j] = 0;
        }
    }
    cout << cnt << nl;
}
int main()
{
    rj
    int t; cin >> t; fr(i, 1, t) cout << "Case " << i << ": ", solve();
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    //solve();
    return 0;
}
