#include<iostream>
#include<vector>
using namespace std;

class UnionFind{
public:
    UnionFind(int n): parent(n), rank(n, 1)
    {
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if(root_x != root_y){
            if(rank[root_x] > rank[root_y]){
                parent[root_y] = root_x;
            }else if(rank[root_x] < rank[root_y]){
                parent[root_x] = root_y;
            }else{
                parent[root_y] = root_x;
                rank[root_x] += 1;
            }
        }
    }

    bool connect(int x, int y){
        return find(x) == find(y);
    }


private:
    vector<int> parent;
    vector<int> rank;

};


int main(){
    UnionFind * uf = new UnionFind(10);
    uf->unite(2,1);
    uf->unite(3,4);
    uf->unite(2,3);
    uf->unite(5,4);
    cout << uf->connect(4,3) << endl;
    return 0;


}
//路径压缩并没有修改秩。