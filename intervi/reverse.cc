#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int i) {
    val = i;
  }
};

ListNode* reverseKGroup(ListNode* head, int k) {
  if (!head || !head->next || k < 2) {
    return head;
  }
  ListNode* prev = head;
  ListNode* tmp = head->next;
  ListNode* new_head = head;
  ListNode* old_head = nullptr;
  ListNode* old_insert = nullptr;
  int count = k-1;
  while (tmp) {
    cout << " val " << tmp->val << endl;
    while (count) {
      prev->next = tmp->next;
      tmp->next = new_head;
      new_head = tmp;
      if (old_insert)
        old_insert->next = new_head;
      if (!tmp->next) {
        return old_head;
      } else {
        tmp = prev->next;
      }
      cout << " count " << count << endl;
      --count;
    }
    if (!old_head) {
      old_head = new_head;
    }
    old_insert = prev;
    count = k - 1;
    new_head = tmp;
    prev = tmp;
    if (tmp)
      tmp = tmp->next;
  }
  return old_head;
}

int main() {
  ListNode* head = nullptr;
  ListNode* prev = nullptr;
   for (int i = 0; i < 2; i++) {
     ListNode* nod = new ListNode(i);
     if (!head)
       head = nod;
     if (prev) {
       prev -> next = nod;
     }
     prev = nod;
   }
   ListNode* new_h = reverseKGroup(head, 2);
   while (new_h) {
     cout << new_h->val << endl;
     new_h = new_h->next;
   }
}
