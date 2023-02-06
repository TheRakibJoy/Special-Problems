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
const int N=1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
struct SQD
{
    string s;
    int cnt[450][26];
    int a,sz;
    char lazy[450];
    int bno(int in)
    {
        return in/sz;
    }
    int getl(int bl)
    {
        return sz*bl;
    }
    int getr(int bl)
    {
        return min(a-1,sz*(bl+1)-1);
    }
    SQD() {}
    SQD(string &s)
    {
        this->s=s;
        a=s.size();
        sz=sqrtl(a);
        memset(cnt,0,sizeof cnt);
        memset(lazy,0,sizeof lazy);
        for(int i=0; i<a; i++)
        {
            int c=s[i]-'a';
            cnt[bno(i)][c]++;
        }
    }
    void clrlzy(int n)
    {
        if(lazy[n]==0)
            return;
        for(int i=getl(n); i<=getr(n); i++)
        {
            s[i]=lazy[n];
        }
        lazy[n]=0;
    }
    void clr(int n)
    {
        for(int i=0; i<26; i++)
            cnt[n][i]=0;
    }
    void update(int l,int r,char c)
    {
        int lf=bno(l),rt=bno(r);
        for(int i=lf+1; i<rt; i++)
        {
            clr(i);
            lazy[i]=c;
            cnt[i][c-'a']=sz;
        }
        clrlzy(lf);
        for(int i=l; i<=min(r,getr(lf)); i++)
        {
            int ch=s[i]-'a';
            cnt[lf][ch]--;
            s[i]=c;
            ch=s[i]-'a';
            cnt[lf][ch]++;
        }
        if(lf!=rt)
        {
            clrlzy(rt);
            for(int i=getl(rt); i<=r; i++)
            {
                int ch=s[i]-'a';
                cnt[rt][ch]--;
                s[i]=c;
                ch=s[i]-'a';
                cnt[rt][ch]++;
            }
        }
    }
    vector<int>query(int l,int r)
    {
        vector<int>ans(26);
        int lf=bno(l),rt=bno(r);
        for(int i=lf+1; i<rt; i++)
        {
            for(int j=0; j<26; j++)
                ans[j]+=cnt[i][j];
        }
        clrlzy(lf);
        for(int i=l; i<=min(r,getr(lf)); i++)
        {
            int ch=s[i]-'a';
            ans[ch]++;
        }
        if(lf!=rt)
        {
            clrlzy(rt);
            for(int i=getl(rt); i<=r; i++)
            {
                int ch=s[i]-'a';
                ans[ch]++;
            }
        }
        return ans;
    }
};
string s,ss;
int a,b;
void solve()
{
    cin>>s>>ss;
    a=s.size();
    b=ss.size();
    SQD sqs(s),sqss(ss);
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int l,r;
            char c;
            cin>>l>>r>>c;
            sqs.update(l-1,r-1,c);
        }
        else if(t==2)
        {
            int l,r;
            char c;
            cin>>l>>r>>c;
            sqss.update(l-1,r-1,c);
        }
        else
        {
            int l1,l2,r1,r2;
            cin>>l1>>r1>>l2>>r2;
            vi f=sqs.query(l1-1,r1-1);
            vi sc=sqss.query(l2-1,r2-1);
            long long ans=(ll)(r1-l1+2)*(r2-l2+2);
            for(int i=0; i<26; i++)
            {
                ans-=(ll)f[i]*sc[i];
            }
            cout<<ans<<nl;
        }
    }
}
int main()
{
    rj
    tst
    //int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    solve();
    return 0;
}
