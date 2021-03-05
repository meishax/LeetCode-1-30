/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(-1);
        ListNode* head = l3;
        int sum;
        bool carry = false;
        while(l1!=NULL||l2!=NULL)
        {
            sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(carry)
            {
                sum++;
                carry=false;
            }
            head->next=new ListNode(sum%10);
            head=head->next;
            if(sum>=10)
            {
                carry=true;
            }
        }
        if(carry)
        {
            head->next = new ListNode(1);
        }
        ListNode* deleteprt=l3;
        l3=l3->next;
        delete deleteprt;

        return l3;


    }
};