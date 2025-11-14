#include <stdio.h>
#include <stdlib.h>

#define MAX 4

struct Queue{
    int items[MAX];
    int front;
    int rear;
    int count;
};

int menu();
void initializeQueue(struct Queue* queue);
int isEmpty(struct Queue* queue);
int isFull(struct Queue* queue);
void enqueue(struct Queue* queue, int value);
void dequeue(struct Queue* queue);
void front(struct Queue* queue);
void displayQueue(const struct Queue* queue);

void initializeQueue(struct Queue* queue){
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

int isEmpty(struct Queue* queue){
    return queue->count == 0;
}

int isFull(struct Queue* queue){
    return queue->count == MAX;
}

void enqueue(struct Queue* queue, int value){
    if(isFull(queue)){
        printf("Kuyruk dolu! Eleman eklenemedi.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = value;
    queue->count++;
    printf("%d kuyruga eklendi.\n", value);
}

void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Kuyruk bos! Eleman silinemedi.\n");
        return;
    }
    int dequeuedValue = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->count--;
    printf("%d kuyruktan cikarildi.\n", dequeuedValue);
}

void front(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Kuyruk bos!\n");
        return;
    }

    int frontValue = queue->items[queue->front];
    printf("Kuyrugun on elemani: %d\n", frontValue);
}

void displayQueue(const struct Queue* queue){
    if (isEmpty(queue)){
        printf("Kuyruk bos.\n");
        return;
    }
    printf("Kuyruk : ");
    int idx = queue->front;
    for (int i = 0; i < queue->count; ++i){
        printf("%d ", queue->items[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int menu(){
    int choice;
    printf("|~~~~~|~ Menu ~|~~~~~|\n");
    printf("1. Kuyruga Eleman Ekleme\n");
    printf("2. Kuyruktan Eleman Silme\n");
    printf("3. On Eleman Bulma\n");
    printf("4. Kuyruga Goster\n");
    printf("5. Cikis\n");
    printf("Secim yapin: ");
    scanf("%d", &choice);
    return choice;
}

int main(){
    struct Queue queue;
    initializeQueue(&queue);

    for(;;){
        int m = menu();
        switch (m){
            case 1:
                printf("Deger girin: \n");
                int value;
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                front(&queue);
                break;
            case 4:
                displayQueue(&queue);
                break;
            case 5:
                printf("Cikis yapildi...\n");
                exit(0);
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }
    return 0;
}