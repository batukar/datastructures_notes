// Bağlı Liste Basa-Sona Ekleme, Silme, Yazdirma
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; // işaretçi 
};

// Prototipler
struct Node* newNode(int newData);
void inputHead(struct Node **head, int newData);
void inputTail(struct Node **head, int newData);
void deleteNode(struct Node **head, int key);
void displayList(const struct Node *head);
int  menu();

struct Node* newNode(int newData){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = newData;
    node->next = NULL;
    return node;
}

void inputHead(struct Node** head, int newData){
    struct Node* n = newNode(newData);
    n->next = *head;
    *head = n;
}

// araya ekle

void inputTail(struct Node** head, int newData){
    struct Node* n = newNode(newData);

    // Liste boşsa
    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

void deleteNode(struct Node** head, int key){
    if (*head == NULL) return;

    // head silme
    if ((*head)->data == key){
        struct Node* del = *head;
        *head = (*head)->next;
        free(del);
        return;
    }

    // ortadan-sondan silme
    struct Node* prev = *head;
    struct Node* curr = (*head)->next;

    while (curr != NULL && curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) return;

    prev->next = curr->next;
    free(curr);
}

void displayList(const struct Node* head){
    printf("\nLinked list: ");
    const struct Node* temp = head;
    while (temp){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

int menu(){
    int choice;
    printf("|~~~~~|~ Menu ~|~~~~~|\n");
    printf("1. Basa Ekle\n");
    printf("2. Sona Ekle\n");
    printf("3. Dügüm Sil\n");
    printf("4. Listeyi Goster\n");
    printf("5. Cikis\n");
    printf("Secim yapin: ");
    scanf("%d", &choice);
    return choice;
}

int main(){
    struct Node* head = NULL;

    for(;;){
        int m = menu();
        switch (m){
        case 1: {
            int x;
            printf("Eklenecek veri: ");
            scanf("%d", &x);
            inputHead(&head, x);
            break;
        }
        case 2: {
            int x;
            printf("Eklenecek veri: ");
            scanf("%d", &x);
            inputTail(&head, x);
            break;
        }
        case 3: {
            int k;
            printf("Silinecek veri: ");
            scanf("%d", &k);
            deleteNode(&head, k);
            break;
        }
        case 4:
            displayList(head);
            break;
        case 5:
            printf("Cikis yapildi...\n");
            return 0;
        default:
            printf("Gecersiz secim.\n");
        }
    }
}