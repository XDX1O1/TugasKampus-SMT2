#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void appendNode(Node **head, int data) {
  Node *newNode = createNode(data);
  if (!newNode) {
    return;
  }

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void reverse(Node **head) {
  Node *prev = NULL;
  Node *current = *head;
  Node *next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *head = prev;
}

void printList(Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

Node *createSampleList() {
  Node *head = NULL;

  appendNode(&head, 1);
  appendNode(&head, 2);
  appendNode(&head, 3);
  appendNode(&head, 4);
  appendNode(&head, 5);

  return head;
}

int main() {
  Node *head = createSampleList();

  printf("Original List: ");
  printList(head);

  reverse(&head);

  printf("Reversed List: ");
  printList(head);

  return 0;
}
