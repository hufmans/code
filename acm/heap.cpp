#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//小根堆 greater<int> 大根堆less<int>，类要重载<
void swap(int &a, int &b){
    //边界情况，当a和b为同一个数时，异或会将这个数变为0
    if(&a != &b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

void HeapInsert(vector<int> &nums, int index){
    while(nums[index] < nums[index / 2]){
        swap(nums[index], nums[index / 2]);
        index /= 2;
    }
}
int heapify(vector<int> &nums){
    int n = nums.size(), index = 0;
    int res = nums.front();

    swap(nums[0],nums[n - 1]);
    //int res = nums.back();  //边界情况，当最后一个元素时0，和n - 1直接通过异或对换，会将数变为0
    nums.pop_back();
    
    while(index * 2 + 1 < n - 1){
        int left = index * 2 + 1;
        int less_index = left + 1 < n - 1 && nums[left] > nums[ left + 1] ? left + 1:left;//这一行通过判断既解决了右子树的存在判断，又判断了大小
        if(nums[index] > nums[less_index]){
            swap(nums[index], nums[less_index]);
            index = less_index;
        }else{
            break;
        }
    }
    return res;
}

class node{
    
public:
    int x, y;
    node(int a, int b): //必须具有显示的构造函数才能使用emplace
    x(a),y(b) {}
    bool operator<(const node & c) const{
        return x < c.x;
    }

};



int main() {
    std::vector<int> heap;
    std::vector<int> elements = {5, 3, 8, 4, 2, 7, 1};

    priority_queue<int,vector<int>, greater<int> > q;
    for(int i = 0; i < elements.size();i++){
        q.push(elements[i]);


    }

    for(int i = 0; i < elements.size(); i++){
        cout << q.top() << ' ';
        q.pop();
    }
    cout << endl;

    priority_queue<node> pq;
    for(int i = 0; i < elements.size(); i++){
        pq.emplace(elements[i],elements[i]);

    }
    
    for(int i = 0; i < elements.size(); i++){
        cout << pq.top().x << ' ';
        pq.pop();
    }
    cout << endl;

    for (int i = 0; i < elements.size(); ++i) {
        heap.push_back(elements[i]);
        HeapInsert(heap, i);
    }
    int n = elements.size();
    for(int i = 0; i < n; i++) {
        cout << heapify(heap) << " ";
    }

    system("pause");
    return 0;
}
