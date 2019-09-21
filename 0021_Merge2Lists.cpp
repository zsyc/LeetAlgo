// 借鉴网友的答案，思路就是用一个新的list，每次比较一个，然后连接小的node

// 注意在c + +实现中，返回函数内部生成的指针可能因函数的销毁才失效。
/**
* Definition for singly - linked list.
* struct ListNode {
    * int val
    * ListNode * next
    * ListNode(int x): val(x), next(NULL) {}
    *}
*/


class Solution {
    public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        if (!l1) return l2
        if (!l2) return l1
        ListNode * head = new ListNode(-100)
        // new定义的对象在函数结束时会被保留，但在外部需要delete
        ListNode * temp = head
        while (l1 & &l2){
            if (l1 -> val > l2 -> val){
                temp -> next = l2
                l2 = l2 -> next
            }
            else{
                temp -> next = l1
                l1 = l1 -> next
            }
            temp = temp -> next
            // 与python不同的是，要注意指针与指针 * 的赋值差别
        }
        if (!l1) temp -> next = l2
        if (!l2) temp -> next = l1
        head = head -> next

        return head
    }
}
