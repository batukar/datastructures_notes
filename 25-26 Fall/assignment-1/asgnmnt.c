#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next; 
};

struct Node *newNode(int newData);
void inputHead(struct Node **head, int newData);
void inputMiddle(struct Node **head, int newData, int key);
void inputTail(struct Node **head, int newData);
void deleteNode(struct Node **head, int key);
void displayList(const struct Node *head);
int menu();

struct Node *newNode(int newData) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = newData;
    node->next = NULL;
    return node;
}

void inputHead(struct Node **head, int newData) {
    struct Node *n = newNode(newData);
    n->next = *head;
    *head = n;
}

void inputMiddle(struct Node **head, int newData, int key) {
    if (*head == NULL) return; 

    struct Node *temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    struct Node *n = newNode(newData);
    n->next = temp->next;
    temp->next = n;
}

void inputTail(struct Node **head, int newData) {
    struct Node *n = newNode(newData);

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

void deleteNode(struct Node **head, int key) {
    if (*head == NULL) return;

    if ((*head)->data == key) {
        struct Node *del = *head;
        *head = (*head)->next;
        free(del);
        return;
    }

    struct Node *prev = *head;
    struct Node *curr = (*head)->next;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) return;

    prev->next = curr->next;
    free(curr);
}

void displayList(const struct Node *head) {
    printf("\nLinked list: ");
    const struct Node *temp = head;

    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n\n");
}

int menu() {
    int choice;
    printf("|~~~~~|~ Menu ~|~~~~~|\n");
    printf("1. Basa Ekle\n");
    printf("2. Araya Ekle\n");
    printf("3. Sona Ekle\n");
    printf("4. Dugum Sil\n");
    printf("5. Listeyi Goster\n");
    printf("6. Cikis\n");
    printf("Secim yapin: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct Node *head = NULL;

    for (;;) {
        int m = menu();
        switch (m) {
            case 1: {
                int x;
                printf("Eklenecek veri: ");
                scanf("%d", &x);
                inputHead(&head, x);
                break;
            }
            case 2: {
                if (head == NULL) {
                    printf("Liste bosken araya eklenemez.\n");
                    continue;
                }
                int x, y;
                printf("Eklenecek veri: ");
                scanf("%d", &x);
                printf("Hangi veriden sonra eklenecek: ");
                scanf("%d", &y);
                inputMiddle(&head, x, y);
                break;
            }
            case 3: {
                int x;
                printf("Eklenecek veri: ");
                scanf("%d", &x);
                inputTail(&head, x);
                break;
            }
            case 4: {
                int k;
                printf("Silinecek veri: ");
                scanf("%d", &k);
                deleteNode(&head, k);
                break;
            }
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Cikis yapildi...\n");
                return 0;
            default:
                printf("Gecersiz secim.\n");
        }
    }
}