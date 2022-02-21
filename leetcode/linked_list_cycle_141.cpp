#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:

	// 这里使用的是记录所有 走过元素 的指针，如果成环则指针必定会再次遇到！
	bool hasCycle(ListNode* head) {
		vector<ListNode*> v;
		v.push_back(head);

		bool flag = false;
		for (ListNode *i = head; i != NULL; i=i->next)
		{
			auto p = find(v.begin(), v.end(), i->next);
			// 说明没找到
			if (p != v.end())
			{
				v.push_back(i->next);
			}
			else
			{
				flag = true;
				break;
			}
		}
		return flag;
		
	}

	// 快慢指针法，一个指针一次走一步，一个指针一次走两步
	// 时间复杂度o(1)
	bool hasCycle2(ListNode* head) {
		if (head == NULL)
		{
			return false;
		}
		// 初始化的时候一个指向头指针，另一个指向头的next
		ListNode* slow = head;
		ListNode* fast = head->next;
		bool flag = false;
		// 如果fast.next是null，再取 fast.next.next会访问错误，因此需要判断是否能够进行下一次循环
		// 即判断要取next的变量不能为null
		while ((slow != NULL) && (fast != NULL) && (fast->next != NULL))
		{

			if (slow == fast)
			{
				flag = true;
				break;
			}
			else
			{
				// 一个走一步，一个走两步
				slow = slow->next;
				fast = fast->next->next;
			}

		}
		return flag;
	}


};