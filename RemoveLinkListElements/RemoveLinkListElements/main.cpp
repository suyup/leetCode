//
//  main.cpp
//  RemoveLinkListElements
//
//  Created by Patrick on 8/10/15.
//  Copyright (c) 2015 sp. All rights reserved.
//

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *slow = head, *fast = head;
        while (fast) {
            while (fast && fast->val == val) {
                fast = fast->next;
            }
            if (fast) {
                slow->val = fast->val;
                fast = fast->next;
            } else if (slow->val == val) {
                head = NULL;
            } else {
                slow->next = NULL;
            }
            slow = slow->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    ListNode *head = new ListNode(2);
    ListNode *second = new ListNode(1);
    head->next = second;
    
    ListNode *res = s.removeElements(head, 1);
    
    delete head;
    delete second;
    return 0;
}
