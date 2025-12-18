#pragma once

typedef struct Node {
    int position;
    struct Node* next;
} Node;

Node* createNode(int pos);
Node* createCircle(int n);
void freeCircle(Node* head);
