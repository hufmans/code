#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> vec(1e6);
vector<int> nums(1e6);
const int inf = 998244353;
void swap(int &b, int &c){
    int tmp = b;
    b = c;
    c = tmp;
}
int main(){
    int n, k;
    cin >> n >> k;
    int a = 1, b = 0, c = 0;
    nums[1] = 1;
    for(int i = 1; i <= n; i++){
        cin >> vec[i];
    }
    for(int i = 2; i <= n; i++){
        nums[i] = a ;
        if(i % 2){
            nums[i] += c;
        }else{
            nums[i] += b;
        }
        swap(b, c);
        nums[i] %= inf;
        if(i - k > 0){
            a = a - nums[i - k];
            //a %= inf;
        }
        if(vec[i] == 1){
            a += nums[i];
            a %= inf;
        }else if(vec[i] == 2){
            b += nums[i];
            b %= inf;
        }else{
            c += nums[i];
            c %= inf;
        }
        
        
    }
    cout << nums[n] << endl;
    return 0;
}