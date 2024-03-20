#include <iostream>
#define number 15
using namespace std;

typedef struct node *treePointer;
typedef struct node{
    int data;
    treePointer leftChild, rightChild;
}node;

// 전위순회 구현
void preorder(treePointer ptr){
    if(ptr){
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
    return;
}

// 중위순회 구현
void inorder(treePointer ptr){
    if(ptr){
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
    return;
}

// 후위순회 구현
void postorder(treePointer ptr){
    if(ptr){
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
    return;
}

int main(){
    node nodes[number + 1];
    for(int i = 1; i <= number; i++){
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    for(int i = 1; i <= number; i++){
        if(i % 2 == 0){
            nodes[i/2].leftChild = &nodes[i];
        }else{
            nodes[i/2].rightChild = &nodes[i];
        }
    }
    preorder(&nodes[1]);
    cout << "\n";
    inorder(&nodes[1]);
    cout << "\n";
    postorder(&nodes[1]);
    cout << "\n";

    return 0;
}