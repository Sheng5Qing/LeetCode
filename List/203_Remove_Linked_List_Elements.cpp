#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //设置头前结点，统一操作
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode *tmp = pre_head;
        while (tmp->next != NULL) {
            if(tmp->next->val == val){
                ListNode* p = tmp->next;
                tmp->next = tmp->next->next;
                delete p;
            }else{
                tmp = tmp->next;
            }   
        }
        head = pre_head->next;
        delete pre_head;
        return head;
    }
};

int main(){

    return 0;
}