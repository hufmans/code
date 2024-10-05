#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<string> vec;
    string temp;
    while(getline(cin, temp,' ')){
    	if(!temp.empty()){
        	vec.push_back(temp);
        }else{
            break;
        }
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(auto &x : vec){
    	cout << x << ' ';
    }
    return 0;
	
}