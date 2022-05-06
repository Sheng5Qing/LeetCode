#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		//设置虚拟头结点，统一操作，否则对第一二个结点需要特殊处理
    	ListNode *dummyHead = new ListNode(0); 
    	dummyHead->next = head;
    	ListNode *cur = dummyHead;
    	while (cur->next != nullptr && cur->next->next != nullptr) {
			ListNode *tmp1 = cur->next;
			ListNode *tmp2 = cur->next->next;
			cur->next = cur->next->next;
			tmp1->next = tmp2->next;
			tmp2->next = tmp1;
			cur = cur->next->next;
    	}
		return dummyHead->next;
  	}
};