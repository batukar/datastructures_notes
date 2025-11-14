// Stack Ekleme-Silme-Yazdirma
#include <stdio.h>
#include <stdlib.h>

#define MAX 4

struct Stack{
    int items[MAX];
    int top;
};

void initializeStack(struct Stack* stack);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, int value);
void pop(struct Stack* stack);
void peek(struct Stack* stack);
void displayStack(struct Stack* stack);
int menu();

void initializeStack(struct Stack* stack){
    stack->top = -1; // boş yığın
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

int isFull(struct Stack* stack){
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, int value){
    if(isFull(stack)){
        printf("Stack dolu! Eleman eklenemedi.\n");
        return;
    }
    stack->items[++stack->top] = value;
    printf("%d yigina eklendi.\n", value);
}

void pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Yigin bos! Eleman silinemedi.\n");
        return;
    }
    int poppedValue = stack->items[stack->top--];
    printf("%d yigindan cikarildi.\n", poppedValue);
}

void peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Yigin bos!\n");
        return;
    }
    int topValue = stack->items[stack->top];
    printf("Yiginin tepe elemani: %d\n", topValue);
}

void displayStack(struct Stack* stack){
    if (isEmpty(stack)) {
        printf("Yigin bos.\n");
        return;
    }
    printf("Yigin elemanlari (ustten alta): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int menu(){
    int choice;
    printf("|~~~~~|~ Menu ~|~~~~~|\n");
    printf("1. Yigina Eleman Ekleme\n");
    printf("2. Yigindan Eleman Silme\n");
    printf("3. Tepe Eleman Bulma\n");
    printf("4. Yigini Goster\n");
    printf("5. Cikis\n");
    printf("Secim yapin: ");
    scanf("%d", &choice);
    return choice;
}

int main(){
    struct Stack stack;
    initializeStack(&stack);

    for(;;){
        int m = menu();
        switch (m){
            case 1:
                printf("Deger girin: \n");
                int value;
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                displayStack(&stack);
                break;
            case 5:
                printf("Cikis yapildi...\n");
                return 0;
            default:
                printf("Gecersiz secim.\n");
        }
    }
}