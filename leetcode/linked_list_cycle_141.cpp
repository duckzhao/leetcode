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

	// ����ʹ�õ��Ǽ�¼���� �߹�Ԫ�� ��ָ�룬����ɻ���ָ��ض����ٴ�������
	bool hasCycle(ListNode* head) {
		vector<ListNode*> v;
		v.push_back(head);

		bool flag = false;
		for (ListNode *i = head; i != NULL; i=i->next)
		{
			auto p = find(v.begin(), v.end(), i->next);
			// ˵��û�ҵ�
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

	// ����ָ�뷨��һ��ָ��һ����һ����һ��ָ��һ��������
	// ʱ�临�Ӷ�o(1)
	bool hasCycle2(ListNode* head) {
		if (head == NULL)
		{
			return false;
		}
		// ��ʼ����ʱ��һ��ָ��ͷָ�룬��һ��ָ��ͷ��next
		ListNode* slow = head;
		ListNode* fast = head->next;
		bool flag = false;
		// ���fast.next��null����ȡ fast.next.next����ʴ��������Ҫ�ж��Ƿ��ܹ�������һ��ѭ��
		// ���ж�Ҫȡnext�ı�������Ϊnull
		while ((slow != NULL) && (fast != NULL) && (fast->next != NULL))
		{

			if (slow == fast)
			{
				flag = true;
				break;
			}
			else
			{
				// һ����һ����һ��������
				slow = slow->next;
				fast = fast->next->next;
			}

		}
		return flag;
	}


};