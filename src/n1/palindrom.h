// структура узла списка
typedef struct Node {
    int data;
    struct Node* next;  // указатель на следующий элемент
} Node;

// создание нового узла
Node* createNode(int value);

// добавление элемента в конец списка
void append(Node** head, int value);

// печать списка
void printList(Node* head);

// очистка памяти списка
void freeList(Node* head);

// проверка списка на симметричность (основная функция)
int isSymmetric(Node* head);

// проверка работы функций
void runSimpleTests();

