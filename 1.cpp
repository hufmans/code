#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
vector<int>  split(string &s){
    istringstream iss(s);
    string tmp;
    vector<int> nums;
    while(getline(iss, tmp,' ')){
        if(!tmp.empty()){
            int x = stoi(tmp);
            nums.push_back(x);
        }
    }
    return nums;
}

int main(){
	int n;
    cin >> n;
    vector< vector<int> > grid;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        grid.push_back(split(temp));    
    }
    vector<int> dis(n, inf);
    priority_queue<pair<int, int> ,vector<pair<int,int> >, greater<pair<int,int>> > pq;
    pq.push({0, 0});
    dis[0] = 0;
    while(!pq.empty()){
        auto [dist, x] = pq.top();
        pq.pop();
        for(int i = 0; i < grid[x].size(); i++){
            pair<int, int> p = {dist + 1, grid[x][i]};
            if(dis[p.second] != inf && (dis[p.second] + p.first) % 2){
                cout << -1 << endl;
                return 0;
            }else{
                if(p.first < dis[p.second]){
                    dis[p.second] = p.first;
                    pq.push(p);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(dis[i] % 2 == 0){
            cout << i;
        }

    }
    for(int i = 0; i < n; i++){
        if(dis[i] % 2 == 1){
            cout << i;
        }

    }
    return 0;

    
}