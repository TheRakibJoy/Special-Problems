//starting with the name of almighty ALLAH
///Author - RakibJoy
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
const int N=1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
void solve()
{
    int a,b;
    cin>>a>>b;
    vi v(a);
    cinv(v)
    vi dp(a);
    for(int k=2;k<=b;k++)
    {
        set<int>s;
        for(int i=a-1;i>=0;i--)
        {
            if(dp[i]==INT_MAX)
            {
                //Not Possible
                continue;
            }
            s.insert(v[i]+dp[i]);//storing last bounds
            auto it=s.upper_bound(v[i]+dp[i]);
            //guranted that we can extend if there exist greater
            if(it==s.end())
            {
                dp[i]=INT_MAX;
            }
            else
            {
                dp[i]=*it-v[i];
                //new difference
            }
        }
    }
    int ans=*min_element(all(dp));
    if(ans==INT_MAX) ans=-1;
    cout<<ans<<endl;
}
int main()
{
    rj
    //int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    solve();
    return 0;
}
