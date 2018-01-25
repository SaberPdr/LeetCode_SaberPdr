/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //输入数字过大就不行了
 /*
 Input:
[2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9]
[5,6,4,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9,9,9,9]
Output:
[-9,0,-4,-4,-6,-9,-7,-4,-9,-4,-2,-7,-8,-8,-6,-2,-6,-9,-7]
Expected:
[7,0,8,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,1,4,3,9,1]
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long a = 0;
        long long b = 0;
        long long n = 1;
        while(l1)
        {
            a += l1 -> val * n;
            n *= 10;
            l1 = l1 -> next;
        }
        n = 1;
        while(l2)
        {
            b += l2 -> val * n;
            n *= 10;
            l2 = l2 -> next;
        }
        long long c = a + b;
        n = 10;
        long long d = c % n;
        c = c/n;
        
        ListNode* l3 = new ListNode(d);
        ListNode* ll = l3;
        while(c)
        {
            d = c % n;
            c /= n;
            ListNode* l4 = new ListNode(d);
            ll -> next = l4;
            ll = ll -> next;
        }
        
        return(l3);
        
    }
};
