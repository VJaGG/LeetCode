
//�����ռ䣬����ṹ
//���ף����������ΪN��ʱ�临�ӶȴﵽO(N)������ռ临�Ӷ�ΪO(1)
//coding����
//����ָ�룬��ָ��һ����һ�Σ���ָ��һ�������Σ�����ָ���β��ʱ����ָ�����м�
//����ķ�ת����ķ���O(N),�߽�����
//ʹ�ö���ռ�һ�������������һ��
/*
�ж�һ�������Ƿ�Ϊ���Ľṹ
����Ŀ�� ����һ�������ͷ�ڵ�head�����жϸ������Ƿ�Ϊ�� �Ľṹ��
���磺 1->2->1������true�� 1->2->2->1������true�� 15->6->15������true�� 1->2->3������false��
���ף� ���������ΪN��ʱ�临�ӶȴﵽO(N)������ռ临�� �ȴﵽO(1)��
*/
#include<stack>
#include<iostream>
using namespace std;
struct node
{
	int val;
	node* next;
	node(int x) :val(x), next(nullptr) {}
};
bool isPalindrome(node* head) {
	stack<int> help;
	node* ptr;
	ptr = head;
	while (ptr) {
		help.push(ptr->val);
		ptr = ptr->next;
	}
	while (!help.empty()) {
		if (help.top() != head->val)
			return false;
		help.pop();
		head = head->next;
	}
	return true;
}
bool isPalindrome1(node* head) {
	stack<int> help;
	node* fast=head;
	node* slow=head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = slow->next;
	while (slow) {
		help.push(slow->val);
		slow = slow->next;
	}
	while (!help.empty()) {
		if (help.top() != head->val)
			return false;
		help.pop();
		head = head->next;
	}
	return true;
}
int main() {
	node* head = new node(1);
	head->next = new node(2);
	head->next->next = new node(2);
	head->next->next->next = new node(1);
	bool res = isPalindrome1(head);
	cout << res << endl;
	system("pause");
	return 0;
}