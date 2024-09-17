#include<bits/stdc++.h>
using namespace std;

//区间合并

typedef pair<int, int> PII;
const int N = 100010;

int n;  // 输入区间的数量
vector<PII> segs;  // 用于存储所有区间的vector

// 合并函数，将重叠区间合并
void merge(vector<PII> &segs) {
    vector<PII> res;  // 存储合并后的区间
    sort(segs.begin(), segs.end());  // 按照区间起点排序

    // 初始化为一个非常小的值，表示起点和终点
    int st = -2e9, ed = -2e9;

    // 遍历所有区间
    for (auto seg : segs) {
        if (ed < seg.first) {  // 如果当前区间和之前的区间没有重叠
            if (st != -2e9) res.push_back({st, ed});  // 将之前的区间加入结果
            st = seg.first, ed = seg.second;  // 更新当前区间为新的区间
        } else {
            ed = max(ed, seg.second);  // 更新区间的终点为两个区间终点的最大值
        }
    }

    if (st != -2e9) res.push_back({st, ed});  // 最后一个区间加入结果
    segs = res;  // 更新segs为合并后的区间
}

int main() {
    cin >> n;  // 读取输入的区间数量

    // 读取所有区间
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});  // 将区间加入segs
    }

    // 调用合并函数
    merge(segs);

    // 输出合并后区间的数量
    cout << segs.size() << endl;

    return 0;
}

// 给定 n nn 个区间 [ l i , r i ] [l_i,r_i][l 
// i
// ​
//  ,r 
// i
// ​
//  ]，要求合并所有有交集的区间。

// 注意如果在端点处相交，也算有交集。

// 输出合并完成后的区间个数。

// 例如：[ 1 , 3 ] [1,3][1,3] 和 [ 2 , 6 ] [2,6][2,6] 可以合并为一个区间 [ 1 , 6 ] [1,6][1,6]。

// 输入格式

// 第一行包含整数 n nn。

// 接下来 n nn 行，每行包含两个整数 l ll 和 r rr。

// 输出格式

// 共一行，包含一个整数，表示合并区间完成后的区间个数。

// 数据范围

// 1 ≤ n ≤ 100000 1≤n≤1000001≤n≤100000,
// − 1 0 9 ≤ l i ≤ r i ≤ 1 0 9 −10^9≤l_i≤r_i≤10^9−10 
// 9
//  ≤l 
// i
// ​
//  ≤r 
// i
// ​
//  ≤10 
// 9
