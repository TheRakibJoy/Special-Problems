//starting with the name of almighty ALLAH
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
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
ll inf = 1e16;
int a, b;
int v[5004];
ll tmp[5004], cst[5004][301];
ll dp[5004][301];
ll goriberDP(int in, int rem)
{
    if (in > a)
    {
        if (rem) return inf;
        return 0;
    }
    auto &ret = dp[in][rem];
    if (~ret) return ret;
    ret = inf;
    for (int i = in; i <= a; i++)
    {
        if (i - in > rem) break;
        ret = min(ret, cst[i][i - in] + goriberDP(i + 1, rem - (i - in)));
    }
    return ret;
}
void solve()
{
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= a; i++)
    {
        scanf("%d", &v[i]);
    }
    if (b > a - 1)
    {
        cout << -1 << nl;
        return;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            cst[i][j] = LLONG_MAX;
            dp[i][j] = -1;
        }
    }
    for (int k = 1; k <= a; k++)
    {
        for (int i = max(k - b, 1); i <= k; i++)
        {
            ll cnt = 1;
            tmp[i] = 0;
            for (int j = i + 1; j <= k; j++)
            {
                tmp[i] += cnt * (v[j] - v[j - 1]);
                cnt++;
            }
        }
        for (int i = min(k + b, a); i >= k; i--)
        {
            ll cnt = 1;
            tmp[i] = 0;
            for (int j = i - 1; j >= k; j--)
            {
                tmp[i] += cnt * (v[j + 1] - v[j]);
                cnt++;
            }
        }
        for (int i = max(k - b, 1); i <= k; i++)
        {
            if (k != 1 && i == 1) continue;
            for (int j = k; j <= min(k + b, a); j++)
            {
                if (j - i > b) break;
                cst[j][j - i] = min(cst[j][j - i], tmp[i] + tmp[j]);
            }
        }
    }
    printf("%lld\n", goriberDP(1, b));
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        //int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
        //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
        solve();
    return 0;
}
