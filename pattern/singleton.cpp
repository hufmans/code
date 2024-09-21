#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class shop{
    vector<string> goods;
    unordered_map<string,int> goodlst;
    shop(){};
    shop(const shop &) = delete;
    ~shop(){};
public:
    static shop * GetInstance(){
        static shop instance;
        return &instance;
    }
    void addCart(string gname, int gcnt){
        if(gname.empty() || gcnt <= 0) return ;
        if(goodlst.count(gname)){
            goodlst[gname] += gcnt;
        }else{
            goods.push_back(gname);
            goodlst[gname] = gcnt;
        }

    }
    void showCart(){
        if(goodlst.empty()) return ;
        for(const auto vec: goods){
            cout << vec << " " << goodlst[vec] << endl;
        }
    }
};

int main(){

    shop * s = shop::GetInstance();
    int cnt;
    string name;
    shop * t = shop::GetInstance();
    while(cin >> name >> cnt){
        s->addCart(name, cnt);
    }
    s->showCart();
    return 0;
    

}