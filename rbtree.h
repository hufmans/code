#pragma once
enum Colour{
    RED,
    BLACK,
};

template <class T>
struct RBTreeNode{
    RBTreeNode<T> * _parent;
    RBTreeNode<T> * _left;
    RBTreeNode<T> * _right;
    T _data;
    Colour _col;

    RBTreeNode(const T& data):
    _parent(nullptr),
    _left(nullptr),
    _right(nullptr),
    _data(data),
    _col(RED)
    {}
    
};

template <class T>
class RBTree{
    //typedef RBTreeNode<T> Node;
public:
    typedef RBTreeNode<T> Node;
    bool Insert(const T& data);
    void InOrder();
    bool IsBlance();
    int TreeHeight();

private:
    int _TreeHeight(Node * root);
    bool _Check(Node * root, int blcakNum, int mark);
    void _InOrder(Node * root);
    void RotateL(Node * parent);
    void RotateR(Node * parent);

private:
    Node * _root = nullptr;
};

template<class T>
int RBTree<T>::_TreeHeight(Node * root){

}
