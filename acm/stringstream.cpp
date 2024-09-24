#include<iostream>
#include<vector>
#include<string>
#include <sstream>
using namespace std;

vector<string> split(const string &s, char delim){
    istringstream iss(s);
    vector<string> vec;
    string tmp;
    while(getline(iss, tmp, delim)){
        if(!tmp.empty()){
            vec.push_back(tmp);
        }
        //vec.push_back(tmp);

    }
    return vec;
}

int main(){
    string s;
    cin >> s;

}