#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param blocked_words string字符串vector 屏蔽字库列表
     * @param nike_name string字符串 需要检查的昵称
     * @return bool布尔型
     */
    struct node{
        char c;
        bool flag;
        map<char, node*> mp;
        node(char x, bool f){
            c = x;
            flag = f;
        }
        //vector<int> vec(26);
    };
    bool CheckNikeNameIsAllowed(vector<string>& blocked_words, string nike_name) {
        // write code here
        node * head = new node('\0',false);
        for(auto &s: blocked_words){
            node * h = head;
            
            //for(char &c : s){
            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                if(!h->mp.count(c)){
                    h->mp[c] = new node(c, false);
                }
                h = h->mp[c];
            }
            h->flag = true;

        }

        
        for(int i = 0; i < nike_name.size(); i++){
            node * t = head;
            for(int j = i; j < nike_name.size(); i++){
                char c = nike_name[j];
                if(t->flag){
                    return false;
                }
                if(!t->mp.count(c)){
                    break;
                }else{
                    t = t->mp[c];
                    if(t->flag){

                        //cout << "false" << endl;
                        return false;
                        //return 0;
                    } 
                }
            }
        }
        //cout << "true";
        return true;


    }
};
int main(){

    Solution s;
    vector<string> bw  = {
        "GameManager", "GM", "exp", "HP", "MP", "kill", "blood", "dog", "money", "shit"
    };
    string nn = "WhoIsGM";
    cout << s.CheckNikeNameIsAllowed(bw,nn);
    return 0;
}