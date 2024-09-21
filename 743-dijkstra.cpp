#include<vector>
#include<queue>
#include<iostream>
using namespace std;

//dijkstra 算法模板
class Solution {
public:
    //vector<vector<int> > graph;
    const int inf = 1e9;
    //vector<vector<int> > graph(n + 1, vector<int>(n + 1));

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int> > graph(n + 1, vector<int>(n + 1, inf));
        for(const auto &vec : times){
            graph[vec[0]][vec[1]] = vec[2];
        }
        vector<int> vis(n + 1);
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
        vector<int> dist(n + 1, inf);
        dist[0] = 0;
        pq.push({0,k});
        

        while(!pq.empty()){
            pair<int,int> q = pq.top();
            pq.pop();
            if(vis[q.second]) continue;

            vis[q.second] = 1;//当从优先队列中取出时才标记
            dist[q.second] = q.first;
             
            
            for(int i = 1;i <= n; i++){
                if(graph[q.second][i] != inf && !vis[i]){
                    
                    int newDist = q.first + graph[q.second][i]; // 
                    if(newDist < dist[i]){
                        dist[i] = newDist;
                        pq.push({newDist, i});
                    }
                }
            }
            
        }
        int me = *max_element(dist.begin() + 1,dist.end());
        int res = me == inf ? -1:me;
        cout <<  res << endl;
        return res; 
    }
};

int main() {
    // Example: (times, n, k) 输入
    std::vector<std::vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    Solution s;
    // 调用函数并输出结果
    int result = s.networkDelayTime(times, n, k);
    std::cout << "Network Delay Time: " << result << std::endl;

    return 0;
}