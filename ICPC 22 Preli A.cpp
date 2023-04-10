//starting with the name of almighty ALLAH
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define dbg(x) cerr<<x<<endl;
#define mp(x,y) make_pair(x,y)
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
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
#define fr(i,a,b) for(int i=a;i<=b;i++)
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
string s[3];
int a;
int dp[302][302];
bool ispos(int i)
{
   if (s[0][i] == 'X') return 0;
   if (s[0][i + 1] == 'X') return 0;
   if (s[1][i] == 'X') return 0;
   if (s[1][i + 1] == 'X') return 0;
   return 1;
}
bool isposd(int i)
{
   if (s[2][i] == 'X') return 0;
   if (s[2][i + 1] == 'X') return 0;
   if (s[1][i] == 'X') return 0;
   if (s[1][i + 1] == 'X') return 0;
   return 1;
}
int goriberDP(int i, int j)
{
   if (j - i < 1) return 0;
   auto &ret = dp[i][j];
   if (~ret) return ret;
   set<int>st;
   for (int k = i; k < j; k++)
   {
      if (ispos(k))
      {
         st.insert(goriberDP(i, k - 1)^goriberDP(k + 2, j));
      }
      if (isposd(k))
      {
         st.insert(goriberDP(i, k - 1)^goriberDP(k + 2, j));
      }
   }
   int mex = 0;
   while (!st.empty())
   {
      int cr = *st.begin();
      if (cr == mex) mex++;
      else break;
      st.erase(st.begin());
   }
   return ret = mex;
}
void solve()
{
   cin >> a;
   cin >> s[0] >> s[1] >> s[2];
   memset(dp, -1, sizeof dp);
   int grundy = goriberDP(0, a - 1);
   if (grundy)
   {
      cout << "Jhinuk" << nl;
   }
   else
   {
      cout << "Grandma" << nl;
   }
}
int main()
{
   rj
   int t; cin >> t; fr(i, 1, t) cout << "Case " << i << ": ", solve();
   //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
   //solve();
   return 0;
}
