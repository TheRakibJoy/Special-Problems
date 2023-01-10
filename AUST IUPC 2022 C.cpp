//starting with the name of almighty ALLAH
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b;
    scanf("%d%d",&a,&b);
    vector<int>deg(a+1);
    vector<long long>dis(a+1);
    map<pair<int,int>,int>m;
    int x,y,z;
    for(int i=0; i<b; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x>y) swap(x,y);
        if(m.find({x,y})!=m.end())
        {
            m[ {x,y}]=min(m[ {x,y}],z);
        }
        else
        {
            m[ {x,y}]=z;
        }

    }
    for(auto it:m)
    {
        x=it.first.first,y=it.first.second;
        z=it.second;
        deg[x]++;
        deg[y]++;
        dis[x]+=(long long)z;
        dis[y]+=(long long)z;
    }
    long long ans=LLONG_MAX;
    for(int i=1; i<=a; i++)
    {
        if(deg[i]==a-1)
        {
            ans=min(ans,dis[i]);
        }
    }
    if(ans==LLONG_MAX)
        puts("Impossible");
    else
        printf("%lld\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
        printf("Case %d: ",i),solve();
    return 0;
}
