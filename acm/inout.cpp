#include<iostream>
#include<vector>
using namespace std;

const int N = 10001;
vector<int> num(N),ml(N),mr(N);//diff(N);
int n,m;

bool check(int mid){
    vector<int> diff(N);
    for(int i = 0; i <= mid; i++){
        diff[ml[i]] += 1;
        diff[mr[i] + 1] -= 1;
    }
    int tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += diff[i];
        if(tmp > num[i]){
            return false;
        }
    }
    return true;
    
}

int main(){
    
    cin >> n >> m;
    //vector<int> num(n),ml(m),mr(m);
    for(int i = 1; i <= n; i ++){
        cin >> num[i];
        
    }
    for(int i = 0; i < m; i++){
        
        cin >> ml[i] >> mr[i];
    }
    int l = 0, r = m - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    if(check(l)) l++;
    cout << l;
    return 0;
}