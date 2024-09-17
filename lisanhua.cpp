#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> alls = {1,2,1,2,3,1,2,3};//存储所有待离散化的值
    sort(alls.begin(),alls.end());//排序
    alls.erase(unique(alls.begin(),alls.end()),alls.end());//去重
    for(int i = 0; i < alls.size(); i++){
        cout << alls[i] << endl;

    }
    return 0;
}

//unique 函数是 C++ 标准库中的一个算法，位于 <algorithm> 头文件中。它的主要作用是对已排序的容器中的相邻重复元素进行去重，但不会直接修改容器的大小。
//它将重复的元素移到序列的末尾，并返回一个新的末尾迭代器，指向去重后的序列的“逻辑终点”。

// alls.erase(unique(alls.begin(), alls.end()), alls.end());:

// unique(alls.begin(), alls.end()) 函数会将重复的元素移到序列的末尾，并返回一个指向新“逻辑终点”的迭代器，保留每个值的第一个出现位置。
// alls.erase(...) 删除从“逻辑终点”到真正末尾之间的元素，完成去重操作。
