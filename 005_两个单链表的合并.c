/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode*list3=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*ptail=list3;
    while(list1!=NULL&&list2!=NULL)
    {
 
	//实际没有再创建新节点，使用的是本来的节点；
	struct ListNode**pnew=(list1->val<=list2->val?(&list1):(&list2));
        ptail->next=*pnew;
        ptail=*pnew;
        *pnew=(*pnew)->next;
    }
    ptail->next=(list1==NULL)?list2:list1;
    return list3->next;
}
