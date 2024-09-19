#include<iostream>
#include<vector>
using namespace std;

class bigint{
    const int MAX_INT = 1e9;
    vector<int> num;
public:
    bigint(){
        num.push_back(0);
    }

    bigint(bigint & bg):
    num(bg.num)
    {}
    bigint(const int x){
        num.push_back(x);
    }
    bigint &operator=(bigint & bg):
    num(bg.num)
    {}


};


int main(){

}