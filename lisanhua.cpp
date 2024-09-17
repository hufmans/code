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