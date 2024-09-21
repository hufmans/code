#include<iostream>
#include<vector>
using namespace std;
void BulleSort(vector<int> &v){
    int n = v.size();
    bool is_swap = false;
    for(int i = 0; i < n;i++){
        for(int j = 0;j < n - i - 1; j++){
            if(v[j + 1] < v[j]){
                is_swap = true;
                int tmp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = tmp;
            }

        }
        if(!is_swap) return ;
    }
}

void QuickSort(vector<int> &v, int l, int r){
    if(l >= r) return ;
    int first = l, last = r, key = v[l];
    
    while(first < last){
        while(v[last] > key && first < last) last--;
        v[first] = v[last];
        while(v[first] < key && first < last) first++;
        v[last] = v[first]; 
    }
    v[first] = key;
    QuickSort(v, l,first);
    QuickSort(v, first+1, r);

}

int main(){
    vector<int> a = {3,1,4,5,7,6,8,2};
    QuickSort(a,0,7);
    for(auto x: a) cout << x;

    return 0;
}