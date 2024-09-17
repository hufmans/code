#include<bits/stdc++.h>
using namespace std;
//离散化算法
//离散化，把无限空间中有限的个体映射到有限的空间中去，以此提高算法的时空效率。
//离散化是程序设计中一个常用的技巧，它可以有效的降低时间复杂度。其基本思想就是在众多可能的情况中，    只考虑需要用的值。

//alls数组中存储所有出现的值
//通过find函数查找从值到标的映射，二分查找
//将原本的数据映射到一个紧密的空间中，使得数组操作更加节约时间和空间。

//关键词：离散化、二分查找，5

// 题目：
// 假定有一个无限长的数轴，数轴上每个坐标上的数都是0。

// 现在，我们首先进行 n nn 次操作，每次操作将某一位置x xx上的数加c cc。

// 接下来，进行 m mm 次询问，每个询问包含两个整数l ll和r rr，你需要求出在区间[ l , r ] [l, r][l,r]之间的所有数的和。

// 输入格式

// 第一行包含两个整数n nn和m mm。

// 接下来 n nn 行，每行包含两个整数x xx和c cc。

// 再接下里 m mm​ 行，每行包含两个整数l ll和r rr。

// 输出格式

// 共m mm行，每行输出一个询问中所求的区间内数字和。

typedef pair<int,int> pii;
vector<pii> p;
vector<pii> query;
vector<int> alls;
int find(int x){
    int l=0,r=alls.size()-1;
    while(l<r){
        int mid=(l+r)>>1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return r+1;
}
int a[300005],sum[300005],n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x,c;
        cin>>x>>c;
        alls.push_back(x);
        p.push_back({x,c});
    }
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l,r});
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for(auto item:p){
        a[find(item.first)]+=item.second;
    }
    for(int i=1;i<=alls.size();i++) sum[i]=sum[i-1]+a[i];
    for(auto item:query){
        int l=find(item.first),r=find(item.second);
        cout<<sum[r]-sum[l-1]<<endl;
    }
}
