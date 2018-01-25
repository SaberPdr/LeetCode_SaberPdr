/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //第一版:转换成数字相加再转换成链表, 输入数字过大就不行了
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

//第二版:缝缝补补while if while
//勉强这个题可以得出正确答案, 但是这么多if while看着就low
//还是得和大佬们多学习啊
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

用LinkList代表整数中每一个数字，模拟加法进位的方式进行求和计算。例如：2 -> 4 -> 3
和5 -> 6 -> 4，先计算个位数 2和5的和为7， 十位数 4和6的和为10，逢十进一，则该位的数字
为0，产生一位进位1到百位参与百位的数字求和。那么百位的结果：3 + 4 + 1（这个1就是刚刚十位
相加产生的进位），百位计算结果为8，所以最终返回结果 7 -> 0 -> 8
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = 0;
        int b = 0;
        int n = 10;
        int d = 0;
        int c = 0;
        
        ListNode* l3 = new ListNode(c);
        ListNode* ll = l3;

        while(l1 != NULL && l2 != NULL)
        {
            a = l1 -> val;
            b = l2 -> val;
            c = (a + b + d) % n;
            d = (a + b + d) / n;
            ListNode* l4 = new ListNode(c);
            ll -> next = l4;
            ll = ll -> next;
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if(l1 == NULL && l2 == NULL && d == 1)
        {
            ListNode* l4 = new ListNode(1);
            ll -> next = l4;
            ll = ll -> next;
        }
        else if(l1 != NULL && l2 == NULL && d == 1)
        {
            while(l1 != NULL)
            {
                a = l1 -> val;

                c = (a + d) % n;
                d = (a + d) / n;
                ListNode* l4 = new ListNode(c);
                ll -> next = l4;
                ll = ll -> next;
            
                l1 = l1 -> next;
            }
            if(l1 == NULL && d == 1)
            {
                ListNode* l4 = new ListNode(1);
                ll -> next = l4;
                ll = ll -> next;
            }
        }
        else if(l1 == NULL && l2 != NULL && d == 1)
        {
            while(l2 != NULL)
            {
                b = l2 -> val;
                c = (b + d) % n;
                d = (b + d) / n;
                ListNode* l4 = new ListNode(c);
                ll -> next = l4;
                ll = ll -> next;
            
                l2 = l2 -> next;
            }
            if(l2 == NULL && d == 1)
            {
                ListNode* l4 = new ListNode(1);
                ll -> next = l4;
                ll = ll -> next;
            }
        }
        if(l1 != NULL)
        {
            ll -> next = l1;
        }
        else if(l2 != NULL)
        {
            ll -> next = l2;
        }

        return l3 -> next;
    }
};
