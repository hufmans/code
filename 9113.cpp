#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> itvs(M, vector<int>(3));
    
    for (int i = 0; i < M; ++i) {
        cin >> itvs[i][0] >> itvs[i][1] >> itvs[i][2];
    }
    
    // Sort intervals based on the end time
    sort(itvs.begin(), itvs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    vector<int> f(10000, 0);
    int pre_max = 0;
    int idx = 0;
    
    for (int i = 1; i < 10000; ++i) {
        if (idx >= M) break; // Check if all intervals are processed
        
        if (i > 0) f[i] = f[i - 1];
        
        while (idx < M && itvs[idx][1] <= i) {
            f[i] = max(f[i], f[itvs[idx][0] - 1] + itvs[idx][2]);
            ++idx;
        }
    }
    
    cout << *max_element(f.begin(), f.end()) << endl;
    
    return 0;
}