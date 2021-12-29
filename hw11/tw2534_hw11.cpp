#include <iostream>  
#include <assert.h>  
#include <math.h>   
#include <queue>  

using namespace std;  

#define RED 0  

#define BLACK 1  

  
template <class T>  

class RBT;  

  
int swaping_the_Color(int swap) {  
 
   return (swap==0)?1:0;  

}  


template <class T>  

 
class RBTNode {  


    RBTNode<T> *par, *leftones, *rightones;  


    T data;  

    int color;  

  
public:  

  

    RBTNode(T data)  

  

            : data(data),  

  

              color(RED),  

  

              par(nullptr),  

  

              leftones(nullptr),  

  

              rightones(nullptr) {}  

  

    friend class RBT<T>;  

  

    void prettyPrint(int takingindentation) const;  

  

   

  

    template <class T1>  

  

    friend void swaping_the_Color(RBTNode<T1> *);  

  

    template <class T1>  

  

    friend int getColor(RBTNode<T1> *);  

  

    template<class T1>  

  

    friend void setColor(RBTNode<T1> *, bool);  

  

   

  

    int height() const;  

  

};  

  

   

  

template <class T>  

  

int RBTNode<T>::height() const {  

  

    int leftside = 0;  

  

    if (leftones != nullptr) {  

  

        leftside = leftones->height();  

  

    }  

  

    int rightside = 0;  

  

    if (rightones != nullptr) {  

  

        rightside = rightones->height();  

  

    }  

  

    return 1 + max(leftside, rightside);  

  

}  

  

   

  

template <class T>  

  

void RBTNode<T>::prettyPrint(int takingindentation) const {  

  

    if (rightones != nullptr) {  

  

        rightones->prettyPrint(takingindentation + 1);  

  

    }  

  

    int travelling = takingindentation * 2;  

  

    for (int k = 0; k < travelling; k++) {  

  

        cout << '\t' ;  

  

    }  

  

    cout << "DATA: " << data << endl;  

  

    for (int m= 0; m < travelling; m++) {  

  

        cout << '\t';  

  

    }  

  

    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;  

  

    if (leftones != nullptr) {  

  

        leftones->prettyPrint(takingindentation + 1);  

  

    }  

  

}  

  

   

  

template <class T>  

  

void swaping_the_Color(RBTNode<T> *node) {  

  

    if (node != nullptr) {  

  

        node->color = swaping_the_Color(node->color);  

  

    }  

  

}  

  

   

  

  

template <class T>  

  

int getColor(RBTNode<T> *node) {  

  

    if (node != nullptr) {  

  

        return node->color;  

  

    }  

  

    return BLACK;  

  

}  

  

   

  

template <class T>  

  

void setColor(RBTNode<T> *node, bool color) {  

  

    if (node != nullptr) {  

  

        node->color = color;  

  

    }  

  

}  

  


template <class T>  

  

class RBT {  

  

    RBTNode<T> *root;  

  

    void singleRotateRight(RBTNode<T> *&pointer);  

  

    void singleRotateLeft(RBTNode<T> *&pointer);  

  

   

  

public:  

  

    RBT() : root(nullptr) {}  

  

   

  

    void insert(const T &);  

  

    void insert(const T &, RBTNode<T> *&pointer, RBTNode<T> *par);  

  

    void fixInsert(RBTNode<T> *pointer);  

  

    void prettyPrint() const { root->prettyPrint(0); }  

  

   

  

    int height() const { return root->height(); }  

  

};  

  

   

  

template <class T>  

  

void RBT<T>::singleRotateRight(RBTNode<T> *&pointer) {  

  

    RBTNode<T> *left_child = pointer->leftones;  

  

    pointer->leftones = left_child->rightones;  

  

    if (pointer->leftones)  

  

        pointer->leftones->par = pointer;  

  

    left_child->par = pointer->par;  

  

    if (!pointer->par)  

  

        root = left_child;  

  

    else if (pointer == pointer->par->leftones)  

  

        pointer->par->leftones = left_child;  

  

    else  

  

        pointer->par->rightones = left_child;  

  

    left_child->rightones = pointer;  

  

    pointer->par = left_child;  

  

}  

  

   

  

template <class T>  

  

void RBT<T>::singleRotateLeft(RBTNode<T> *&pointer) {  

  

    RBTNode<T> *right_child = pointer->rightones;  

  

    pointer->rightones = right_child->leftones;  

  

    if (pointer->rightones)  

  

        pointer->rightones->par = pointer;  

  

    right_child->par = pointer->par;  

  

    if (!pointer->par)  

  

        root = right_child;  

  

    else if (pointer== pointer->par->leftones)  

  

        pointer->par->leftones = right_child;  

  

    else  

  

        pointer->par->rightones = right_child;  

  

    right_child->leftones = pointer;  

  

    pointer->par = right_child;  

  

}  

  

   

  

template <class T>  

  

void RBT<T>::fixInsert(RBTNode<T> *pointer) {  

  

    RBTNode<T> *par = nullptr;  

  

    RBTNode<T> *grandparent = nullptr;  

  

    while (pointer != root && getColor(pointer) == RED && getColor(pointer->par) == RED) {  

  

        par = pointer->par;  

  

        grandparent = par->par;  

  

        if (par == grandparent->leftones) {  

  

            if (getColor(grandparent->rightones) == RED) {  

  

                swaping_the_Color(grandparent->rightones);  

  

                swaping_the_Color(par);  

  

                setColor(grandparent, RED);  

  

                pointer = grandparent;  

  

            } else {  

  

                if (pointer == par->rightones) {  

  

                    singleRotateLeft(par);  

  

                    pointer = par;  

  

                    par = pointer->par;  

  

                }  

  

                singleRotateRight(grandparent);  

  

                swaping_the_Color(par);  

  

                swaping_the_Color(grandparent);  

  

                pointer = par;  

  

            }  

  

        }  

  

        else {  

  

            if (getColor(grandparent->leftones) == RED) {  

  

                swaping_the_Color(grandparent->leftones);  

  

                swaping_the_Color(par);  

  

                setColor(grandparent, RED);  

  

                pointer = grandparent;  

  

            } else {  

  

                if (pointer == par->leftones) {  

  

                    singleRotateRight(par);  

  

                    pointer = par;  

  

                    par = pointer->par;  

  

                }  

  

                singleRotateLeft(grandparent);  

  

                swaping_the_Color(par);  

  

                swaping_the_Color(grandparent);  

  

                pointer = par;  

  

            }  

  

        }  

  

    }  

  

    setColor(root, BLACK);  

  

}  

  

   

  

template <class T>  

  

void RBT<T>::insert(const T &toInsert, RBTNode<T> *&pointer, RBTNode<T> *par) {  

  

    if (pointer == nullptr) {                 

  

        pointer = new RBTNode<T>(toInsert);  


        pointer->par = par;  

  

        fixInsert(pointer);  

  

    }  

  

    else if (toInsert < pointer->data) {   

  

        insert(toInsert, pointer->leftones, pointer);  

  

    } else {    

  

        insert(toInsert, pointer->rightones, pointer);  

  

    }  

  

}  

  


template <class T>  

  

void RBT<T>::insert(const T &toInsert) {  

  

    insert(toInsert, root, nullptr);  

  

}  


int main() {  

  

    RBT<int> b;  

  

    int count = 10;  

  

    for (int i = 0; i < count; i++) {  

  

        b.insert(i);  

  

    }  

  

   

  

    b.prettyPrint();  

  

      

  

    int height = b.height();  

  

    assert(height <= 2 * log2(count));  

  

}  

 

 