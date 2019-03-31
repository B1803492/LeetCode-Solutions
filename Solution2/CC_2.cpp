//Runtime: 28 ms, faster than 99.36% of C++ online submissions for Add Two Numbers.
//Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Add Two Numbers.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int carry = 0;
	void singleDigitAdd(ListNode* a, ListNode* b) {
		int vala, valb = 0;
		vala = (a == NULL) ? 0 : a->val;
		valb = (b == NULL) ? 0 : b->val;
		int temp = vala + valb + carry;
		if (temp >= 10)
		{
			carry = 1;
			if (a != NULL)
			{
				a->val = temp - 10;
			}
			if (b != NULL)
			{
				b->val = temp - 10;
			}
		}
		else
		{
			carry = 0;
			if (a != NULL)
			{
				a->val = temp;
			}
			if (b != NULL)
			{
				b->val = temp;
			}
		}
	}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pointer1 = l1;
        ListNode* pointer2 = l2;
        ListNode* tail1 = NULL;
        ListNode* tail2 = NULL;
        ListNode* result = NULL;
        ListNode* rtail = NULL;
        int length1 = 0;
        int length2 = 0;
        while (pointer1 != NULL || pointer2 != NULL) {
            singleDigitAdd(pointer1, pointer2);
            if (pointer1 != NULL) {
                length1 += 1;
                if (pointer1->next == NULL) {
                tail1 = pointer1;
                }
                pointer1 = pointer1->next;
            }
            if (pointer2 != NULL) {
                length2 += 1;
                if (pointer2->next == NULL) {
                tail2 = pointer2;
                }
                pointer2 = pointer2->next;
            }
        }
        result = (length1 >= length2)? l1:l2;
        rtail = (length1 >= length2)? tail1:tail2;
        if (carry == 1) {
            rtail->next = new ListNode(1);
        }
        return result;
    }
};
