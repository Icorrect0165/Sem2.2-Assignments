#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Question 1: Detecting Cycle in a Linked List
bool hasCycle(ListNode *head) {
    if (!head || !head->next)
        return false;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

// Question 2: Finding the Start of Cycle in a Linked List
ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}

// Question 3: Reversing a Linked List
ListNode *reverseList(ListNode *head) {
    if (hasCycle(head)) {
        std::cout << "Cannot reverse a linked list with a cycle." << std::endl;
        return nullptr;
    }

    ListNode *prev = nullptr;
    ListNode *current = head;

    while (current) {
        ListNode *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main() {
    // Example usage and testing
    // Creating a sample linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // creating a cycle

    // Testing Question 1: Detecting Cycle in a Linked List
    std::cout << "Does the linked list have a cycle? " << (hasCycle(head) ? "Yes" : "No") << std::endl;

    // Testing Question 2: Finding the Start of Cycle in a Linked List
    ListNode *cycleStart = detectCycle(head);
    if (cycleStart)
        std::cout << "The cycle starts at node with value: " << cycleStart->val << std::endl;
    else
        std::cout << "There is no cycle in the linked list." << std::endl;

    // Testing Question 3: Reversing a Linked List
    ListNode *reversedHead = reverseList(head);
    if (reversedHead) {
        std::cout << "Reversed linked list: ";
        while (reversedHead) {
            std::cout << reversedHead->val << " ";
            reversedHead = reversedHead->next;
        }
        std::cout << std::endl;
    }

    return 0;
}
