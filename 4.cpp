#include<bits/stdc++.h>
using namespace std;
vector<char> vec;
void binary_find(vector<int> &nums,int y,int l, int r){
    if(l >= r){
        vec.pop_back();
        vec.push_back('N');
        return ;
    }
    int mid = (l + r) / 2;
    
    if(mid == nums.size() / 2){
        vec.push_back('S');
    }
    if(nums[mid] == y){
        vec.push_back('Y');
        
    }else if(nums[mid] < y){
        vec.push_back('R');
        binary_find(nums,y,mid+1, r);
    }else{
        vec.push_back('L');
        binary_find(nums, y, l,mid);
    }
    return ;
}

int main(){
    int x,y;
    vector<int> nums;
    string l;
    
    getline(cin, l);
    istringstream iss(l);
    while(iss >> x){
        nums.push_back(x);
   
    }
    sort(nums.begin(),nums.end());  
    cin >> y;
    binary_find(nums,y,0, nums.size());
    for(auto &t:vec){
        cout << t;
    }
    return 0;
}