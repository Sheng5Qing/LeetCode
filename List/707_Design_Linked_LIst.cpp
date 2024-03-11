#include <iostream>

class MyLinkedList {
public:
    //链表结点结构体
    typedef struct LinkedNode{
        int val;
        LinkedNode *next;
        LinkedNode(int val):val(val),next(nullptr){}
    }LinkedNode;

    MyLinkedList() {
        //虚拟头结点
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= _size){
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        //index从0开始
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        ++_size;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        ++_size;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > _size){
            return;
        }
        LinkedNode* cur = _dummyHead;
        LinkedNode* newNode = new LinkedNode(val);
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        ++_size;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > _size){
            return;
        }
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        if(index != _size - 1){
            cur->next = cur->next->next;
        }else{
            cur->next = nullptr;
        }
        delete tmp;
        --_size;
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};