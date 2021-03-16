#include "Solution.h"
#include <vector>

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    if (head==nullptr)
        return nullptr;

    if (head->next == nullptr && n==1)
        return nullptr;

    std::vector<ListNode*> vectors;

    ListNode *curr = head;
    while (curr != nullptr)
    {
        vectors.push_back(curr);
        curr = curr ->next;
    }

    int indexOfItemToDelete = (vectors.size() - n);

    // If we are deleting the first node (which has an index of 0 in our vector), then just return the second node.
    if (indexOfItemToDelete ==0)
        return head->next;
    
    vectors[indexOfItemToDelete-1]->next = vectors[indexOfItemToDelete+1];
    return head;
}
