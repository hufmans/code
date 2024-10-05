#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nums(1e5, 1);
vector<int> res(1e5);

int main() {
    // for(int i = 0; i <= 1e9; i++){
    //     nums[i] = i - 1;
    // }
    int n ,m, maxy = 0;
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int x, y;
        cin >> x >> y;
        nums[y] = y - x;
        maxy = max(y, maxy); 
    }
    // for(int i = 1; i <= max(maxy,n); i++){
    //     res[i] = res[i - 1 + nums[i]] + 1;   
    //     if(nums[i]){
    //         for(int j = i; j > i + nums[i] ;j--){
    //             res[j] = min(res[j], res[i] + i - j);
    //         }
    //     }
    // }
    // cout << res[n] << endl;
    // return 0;
    for(int i =1; i <= max(maxy,n); i++){
        //nums[i] += nums[i  - 1] + 1;
        if(nums[i] != 1){
            int k = nums[i];
            nums[i] = nums[i  - nums[i]];
            for(int j = i; j > i - k; j--){
                nums[j] = min(nums[i] + i - j,nums[j]);
            }
        }else{
            nums[i] = nums[i  - 1] + 1;
        }
    }
    cout << nums[n]  - 2 << endl;
    return 0;
}