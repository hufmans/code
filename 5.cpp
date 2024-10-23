#include<bits/stdc++.h>
using namespace std;

string its(int x, int p){
    ostringstream oss;
    oss << setw(p) << setfill('0') << x;
    return oss.str();
}

int main(){
    int n, m;
    cin >>  n >> m;
    vector<string> vec;
    string s; 
    for(int i = 0; i < n; i++){
        cin >> s;
        int a = 0, b = 0, c = 0,max_b = 0;
        for(int i = 0; i < m; i++){
            if(s[i] == '1'){
                a++;
                if(i >= 1 && s[i - 1] == '1'){
					b++;
                }
                max_b = max(max_b,b);
            }else{
                b = 0;
                c = c *10 + (i + 1);
            }
            string temp;
            temp.append(its(a,4));
            temp.append(its(max_b + 1,4));
            temp.append(to_string(c));
            temp.append(to_string(i + 1));
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end());
        for(auto &y : vec){
            cout << y[y.size() - 1]<< ' ';
           
        }
        return 0;
    }
    
}