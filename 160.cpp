#include<iostream>
using namespace std;

/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
*/

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL)
        {
            ++lenA;
            tempA=tempA->next;
        }
        while(tempB!=NULL)
        {
            ++lenB;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(lenA>lenB)
        {
            int del=lenA-lenB;
            while(del!=0)
            {
                tempA=tempA->next;
                --del;
            }
        }
        else
        {
            int del=lenB-lenA;
            while(del!=0)
            {
                tempB=tempB->next;
                --del;
            }
        }
        while(tempA!=NULL)
        {
            if(tempA==tempB)
            {
                return tempA;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};