#include <iostream>

struct Node {
  int val;
  Node* next = nullptr;
};

void reverser_list(Node* head) {
  if (!head) {
     return;
  }
  bool first = true;
  Node* tmp, nxt;
  Node* index = head;
  Node* new_head = head;
  while(index->next) {
    nxt = index->next;
    if (!nxt) {
      return;
    }
    if (nxt->next) {
      index->next = nxt->next;
      nxt->next = new_head;
      new_head = nxt;
    } else {
      nxt->next = new_head;
    }
    if (first)
      new_head->next = nullptr;
    first = false;
    index = index->next;
  }
  head = new_head;
  return;
}

A --> B --> C
head = A

A-> next = C
B ->next =  A;

B -> A- > C
index =  A

C -> B

C-> B -> A




int main() {
  
}
