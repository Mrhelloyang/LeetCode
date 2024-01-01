#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* head = NULL, * tail = NULL, * pnew;
	int sum = 0;
	int Sum = 0;
	int i = 1;
	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		sum = (n1 + n2 + Sum) % 10;//这个用来存个位数；
		Sum = (n1 + n2 + Sum) / 10;//这个用来存的十位数
		if (i == 1)
		{
			head = (struct ListNode*)malloc(sizeof(struct ListNode));
			head->val = sum;
			head->next = NULL;
			tail = head;
		}
		else
		{
			pnew = (struct ListNode*)malloc(sizeof(struct ListNode));
			pnew->val = sum;
			pnew->next = NULL;
			tail->next = pnew;//连接
			tail = pnew;
		}
		i++;
		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	if (Sum != 0)
	{
		pnew = (struct ListNode*)malloc(sizeof(struct ListNode));
		pnew->val = Sum;
		pnew->next = NULL;
		tail->next = pnew;//连接
		tail = pnew;
	}
	return head;
}
int main()
{
	struct ListNode* tmp = NULL;
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	struct ListNode* pnew = NULL;
	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1->val = 9;
	tmp = l1;
	for (int i = 0; i < 6; i++)
	{
		pnew = (struct ListNode*)malloc(sizeof(struct ListNode));
		pnew->val = 9;
		pnew->next = NULL;
		tmp->next = pnew;//接上
		tmp = pnew;//往后移
	}
	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	tmp = l2;
	l2->val = 9;
	for (int i = 0; i < 3; i++)
	{
		pnew = (struct ListNode*)malloc(sizeof(struct ListNode));
		pnew->val = 9;
		pnew->next = NULL;
		tmp->next = pnew;//接上
		tmp = pnew;//往后移
	}
	struct ListNode* head = addTwoNumbers(l1, l2);
	tmp = head;
	for (int i = 0; i < 8; i++)
	{
		printf("%d,", tmp->val);
		tmp = tmp->next;
	}
	printf("hellomike\n");
	return 0;
}