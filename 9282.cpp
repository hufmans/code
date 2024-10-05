#include<bits/stdc++.h>
using namespace std;

int main(){
    string x;
    cin >> x;
    int i = 0, j = x.size();
    vector<int> y(1e6);
    while(i < j){
        y[i] += x[i] - x[j];
        if(y[i] < 0){
                y[i] = 10 - y[i];
                y[i + 1] = -1;
            }
        i++;
        j--;
    }
    if(y[i] < 0){
        y[i] = 10 - y[i];
        y[i + 1] = x[i + 1]-'1';
    }
    for(auto i = y.rend();i != y.rbegin(); i++){
        cout << *i;
    }
    return 0;
}