#pragma once
using namespace std;
// https://blog.csdn.net/weixin_60521256/article/details/137234303
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
    if(root == nullptr)
        return 0;
    int rightH = _TreeHeight(root->_right);
    int leftH = _TreeHeight(root->_left);
    return rightH > leftH ? rightH + 1 : leftH + 1;
}

template<class T>
bool RBTree<T>::_Check(Node * root, int blackNum, int mark){
    if (root == nullptr){
        if (blackNum == mark){
            cout << "存在黑色节点数不相等" << endl;
            return false;
        }
        return true;
    }

    if (root->_col == BLACK)
        ++blackNum;

    if (root->_col == RED && root->_parent->_col == RED){
        cout << "出现连续红色节点" << endl;
        return false;
    }

    return _Check(root->_left, blackNum, mark) && 
            _Check(root->_right, blackNum, mark);

}

template<class T>
void RBTree<T>::_InOrder(Node * root){
    if (root == nullptr){
        return ;
    }
    _InOrder(root->_left);
    cout << root->_data << " ";
    _InOrder(root->_right);

}

template<class T>
void RBTree<T>::RotateL(Node * parent){
    Node* subR = parent->_right;
        Node* subRL = subR->_left;

        //旋转并更新_parent指针
        parent->_right = subRL;
        if (subRL)
            subRL->_parent = parent;

        //先保存一下parent->_parent，因为下面会改它
        Node* pparent = parent->_parent;

        //旋转并更新_parent指针
        subR->_left = parent;
        parent->_parent = subR;

        //若pparent为空则证明旋转的是一整棵树，因为根结点的_parent为空
        if (pparent == nullptr)
        {
            //subR是新的根
            _root = subR;
            _root->_parent = nullptr;
        }
        //若pparent不为空，则证明旋转的是子树，parent上面还有结点
        else
        {
            //让pparent指向子树旋转之后新的根
            if (pparent->_left == parent)
            {
                pparent->_left = subR;
            }
            else
            {
                pparent->_right = subR;
            }
            //同时也让新的根指向pparent
            subR->_parent = pparent;
        }
}


template<class T>
void RBTree<T>::RotateR(Node * parent){
    Node* subL = parent->_left;
        Node* subLR = subL->_right;

        //旋转并更新_parent指针
        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;

        //先保存一下parent->_parent，因为下面会改它
        Node* pparent = parent->_parent;

        //旋转并更新_parent指针
        subL->_right = parent;
        parent->_parent = subL;

        //若parent等于_root则证明旋转的是一整棵树（这也是一种判断方法）
        if (parent == _root)
        {
            _root = subL;
            _root->_parent = nullptr;
        }
        else
        {
            //让pparent指向子树旋转之后新的根
            if (parent == pparent->_left)
            {
                pparent->_left = subL;
            }
            else
            {
                pparent->_right = subL;
            }
            //同时也让新的根指向pparent
            subL->_parent = pparent;
        }
}

template<class T>
bool RBTree<T>::Insert(const T & data){
    if (_root == nullptr)
        {
            _root = new Node(data);
            _root->_col = BLACK;
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur)
        {
            if (data < cur->_data)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (data > cur->_data)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false;
            }
        }
        //走到这里cur为空，就是key应该插入的位置
        cur = new Node(data);
        //链接
        if (data < parent->_data)
            parent->_left = cur;
        if (data > parent->_data)
            parent->_right = cur;

        //链接父亲指针
        cur->_parent = parent;

        //如果插入之后它的parent是红的，就需要进行调整
        while (parent && parent->_col == RED)
        {
            Node* grandfather = parent->_parent;
            //如果父亲是祖父的左孩子，那右孩子就是叔叔
            if (parent == grandfather->_left)
            {
                Node* uncle = grandfather->_right;
                //这里处理的情况是叔叔存在且为红，变色+向上继续处理
                if (uncle && uncle->_col == RED)
                {
                    //将p,u改为黑，g改为红
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandfather->_col = RED;

                    //更新cur为grandfather，判断它的父亲是什么情况：
                    //1.如果不存在或者为黑，就需要继续处理了，也不会进行循环了
                    //2.如果它的父亲存在且为红，重新循环进行调整
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else//叔叔不存在/叔叔存在且为黑的情况
                {
                    //     g
                    //   p   u
                    // c 
                    if (cur == parent->_left)//左左——右单旋+变色
                    {
                        RotateR(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else//左右——左右双旋+变色
                    {
                        //     g
                        //   p   u
                        //     c
                        RotateL(parent);
                        RotateR(grandfather);
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    //这里调整完就可以break了，因为颜色都变的合适了，而相关的链接关系旋转会帮我们处理
                    break;
                }
            }
            //如果父亲是祖父的右孩子，那左孩子就是叔叔
            else //parent = grandfather->_right
            {
                Node* uncle = grandfather->_left;
                //这里处理的情况是叔叔存在且为红
                if (uncle && uncle->_col == RED)
                {
                    //将p,u改为黑，g改为红
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandfather->_col = RED;

                    //更新cur为grandfather，判断它的父亲是什么情况：
                    //1.如果不存在或者为黑，就需要继续处理了，也不会进行循环了
                    //2.如果它的父亲存在且为红，重新循环进行调整
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else
                {
                    if (cur == parent->_right)//右右——左单旋+变色
                    {
                    //    g
                    //  u   p
                    //        c
                        RotateL(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else//右左——右左双旋+变色
                    {
                    //    g
                    //  u   p
                    //    c
                        RotateR(parent);
                        RotateL(grandfather);
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;
                }
            }
        }
        //上面处理过程中有可能会把根变成红色，这里统一处理一下，把根置成黑
        _root->_col = BLACK;
        return true;

}
template<class T>
void RBTree<T>::InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }
template<class T>
bool RBTree<T>::IsBlance()
{
    if (_root && _root->_col == RED)
    {
        cout << "根结点是红色" << endl;
        return false;
    }

        //先求出一条路径黑色结点数量
    int mark = 0;
    Node* cur = _root;
    while (cur)
    {
        if (cur->_col == BLACK)
            ++mark;
        cur = cur->_left;
    }

        //检查是否出现连续红色结点及所有路径黑色结点数量是否相等
    return _Check(_root, 0, mark);
}

template<class T>
int RBTree<T>::TreeHeight()
{
    return _TreeHeight(_root);
}