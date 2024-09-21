#include<iostream>
using namespace std;

template <class T>
struct LinkNode{
    T data;
    LinkNode<T> * Link;
    LinkNode(LinkNode<T> * ptr = NULL) {Link = ptr;}// 构造函数
    LinkNode(const T &item, LinkNode<T> *ptr = NULL) {data = item;Link = ptr;}//
};

template <class T>
class List
{
private:
    /* data */
protected:
    LinkNode<T> *first;
public:
    List(){first = new LinkNode<T>;}// 构造函数
    List(const T &x){first = new LinkNode<T>(x);} //构造函数
    List(List<T> & L); //拷贝构造函数
    ~List(){makeEmpty();} //析构函数
    void makeEmpty();
    int Length();
    LinkNode<T> * getHead() {return first;}
    LinkNode<T> * Search(T x);
    LinkNode<T> * Locate(int i);
    bool getData(int i, T &x);
    void setData(int i, T &x);
    bool Insert(int i, T &x);
    bool Remove(int i, T &x);
    bool IsEmpty() {return first->Link == NULL;}
    bool IsFull() {return false;}
    void Sort();
    void inputFront(T endTag);// 这里的end Tag是什么意思
    void inputRear(T endTag);
    void output();
    List<T> &operator=(List<T> &L);

};

template <class T>
List<T>::List(List<T> &L){
    LinkNode<int> * srcptr = L.first;
    LinkNode<int> * destptr = new LinkNode<T>;
    this->first = destptr;
    while(srcptr->Link != NULL){
        destptr->Link = new LinkNode(srcptr->Link->data);
        destptr = destptr->Link;
        srcptr = srcptr->Link;
    }
    destptr->Link =NULL;

};

template <class T>
void List<T>::makeEmpty(){
    LinkNode * q;
    while(first->Link != NULL){
        q = first->Link;
        first->Link = q->Link;
        delete q; //整个对象只保留头指针
    }
};

template <class T>
int List<T>::Length(){
    LinkNode<T> * p = first;
    int count = 0;
    while(p->Link != NULL){
        p = first->Link;
        count++;
    }
    return count;
};


template<class T>
LinkNode<T> * List<T>::Search(T x){
    LinkNode<T> * p = first->Link;
    while(p != NULL){
        if(p->data == x){
            return p;
        }
        p = p->Link;
    }
    return NULL;
};

template<class T>
LinkNode<T> * List<T>::Locate(int i){
    int j = 0;
    LinkNode<T> * p = first->Link;
    while(p != NULL && j < i){
        p = p->Link;
        j++;
    }
    return p;//如果i大于链表的长度，随着遍历直接返回NULL

};

template<class T>
bool List<T>::getData(int i, T &x){
    LinkNode<T> *p = Locate(i);
    if(p == NULL) {return false;}
    else {
        x = p->data;
        return true;
    }
};

template<class T>
void List<T>::setData(int i, T &x){
    LinkNode<T> * p = Locate(i);
    if(p != NULL){
        p->data = x;
    }
    return ;
}

template<class T>
bool List<T>::Insert(int i, T &x){
    // 将元素插入到第i个节点之后
    LinkNode<T> * p = Locate(i);
    if(p == NULL){return false;}
    
    LinkNode<T> * newNode =  new LinkNode<T>(x);
    if(newNode == NULL){
        cerr << "存储分配错误" << endl;
        return false;

    }
    newNode->Link = p->Link;
    p->Link = newNode;
    return true;
};
template<class T>
bool List<T>::Remove(int i, T &x){
    LinkNode<T> * p = Locate(i);
    if(p == NULL){return false;}
    x = p->data;
    LinkNode<T> * q = Locate(i - 1);
    q->Link = p->Link
    delete p;
    return true;
};

template<class T>
void List<T>::output(){
    LinkNode<T> * p = first->Link;
    while(p != NULL){
        cout << p->data;
        p = p->Link;
    }
    cout << endl;

};

template<class T>
List<T>& List<T>::operator=(List<T> &L){
    LinkNode<T> * srcptr = L.getHead()->Link;
    LinkNode<T> * destptr = new LinkNode<T>;
    this->first = destptr;
    while(srcptr != NULL){
        destptr->Link = new LinkNode<T>(srcptr->data);
        destptr = destptr->Link;
        srcptr = srcptr->Link;
    
    }
    destptr->Link = NULL;
    return *this; ////
};

template<class T>
void List<T>::inputFront(T endTag){
    //endTag 表示结束标志，键盘输入链表数据，如果与endTag相等则停止前插
    LinkNode<T> * newNode;
    T val;
    makeEmpty();
    cin >> val;
    while(val != endTag){
        newNode = new LinkNode<T>(val);
        if(newNode == NULL){cerr << "存储分配错误" << endl; return ;}
        newNode->Link = first->Link;
        first->Link = newNode;
        cin >> val;
    }

};

template<class T>
void List<T>::inputRear(T endTag){
    LinkNode<T> * newNode,* p;
    T val;
    makeEmpty();
    p = first;
    cin >> val;
    while(val != endTag){
        newNode = new LinkNode<T>(val);
        if(newNode == NULL){cerr << "存储分配错误" << endl; return ;}
        p->Link = newNode;
        p = p->Link;
        cin>> val;
    }
    p->Link=NULL
}

int main(){
    
}





