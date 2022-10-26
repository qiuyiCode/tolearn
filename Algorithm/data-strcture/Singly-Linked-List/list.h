#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node{
    int val;
    struct Node *next;
}node;

typedef node* pnode; // 定义一个指向结构的指针声明

void init(pnode *head){
    (*head) = (node*)malloc(sizeof(node));
    (*head)->next = nullptr;
}

// 判断链表是否为空
bool isEmpty(pnode *head){
    return !(*head)->next; // 判断头节点后是否非空
}

// 向头部添加元素
void addNewItemtoHead(pnode *head,int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = x;
    newNode->next = (*head)->next;
    (*head)->next = newNode;
}


// 往尾后添加元素
void addNewItemtoTail(pnode *head,int x){
    pnode p = *head;
    while(p->next != nullptr) p = p->next;

    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = x;
    newNode->next = p->next;
    p->next = newNode;
}

//计算链表中的项数
size_t listCount(pnode *head){
    pnode p = (*head)->next;

    size_t count = 0;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

// 往位置k后添加元素x
bool insert(pnode *head,int k,int x){
    pnode p = (*head);
    for(int i = 0;i < k;i++){
        if(p)
            p = p->next;
        else
            return false;
    }

    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = x;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

void deleteItem(pnode *head,int k){
    pnode p = (*head);
    for(int i = 0;i < k-1;i++){
        if(p){
            p = p->next;
        }
    }

    p->next = p->next->next;

}

void Traversal(pnode *head,void (*pfun)(int data)){
    if((*head)->next != nullptr){
        pnode p = (*head)->next;
        while(p != nullptr){
            (*pfun)(p->val);
            p = p->next;
        }
    }
}

// 链表倒置操作
void Reverse_link(pnode *head){
    pnode p = (*head)->next,q = p;
    (*head)->next = nullptr;

    while(q != nullptr){
        q = q->next;
        p->next = (*head)->next;
        (*head)->next = p;
        p = q;
    }
}

// void print(pnode *head){
//     if((*head)->next != nullptr){
//         pnode p = (*head)->next;
//         while(p != nullptr){
//             cout << p->val << ' ';
//             p = p->next;
//         }
//     }
// }

