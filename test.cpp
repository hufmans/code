#include<iostream>
#include"rbtree.h"
using namespace std;

int main(){
    RBTree<int> rb;
    for(int i = 0; i < 10; i++){
        rb.Insert(i);
    }
    rb.InOrder();
    return 0;
    
}