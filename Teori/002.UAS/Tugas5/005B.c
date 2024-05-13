#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

Node *createNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void insertNode(Node **head, int data) {
  Node *node = createNode(data);
  if (*head == NULL) {
    *head = node;
  } else {
    Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = node;
    node->prev = current;
  }
}

void traverse(const Node *head) {
  printf("Original List : ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void reverseTraverse(const Node *head) {
  if (head == NULL) {
    return;
  }
  reverseTraverse(head->next);
  printf("%d ", head->data);
}

int main() {
  Node *head = NULL;

  insertNode(&head, 1);
  insertNode(&head, 2);
  insertNode(&head, 3);

  traverse(head);
  printf("Traversed List : ");
  reverseTraverse(head);
  printf("\n");

  return 0;
}
