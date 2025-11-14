// Stack Ekleme-Silme-Yazdirma
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

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
int rand01();
int randBetween(int num);

void initializeStack(struct Stack* stack){
    stack->top = -1; 
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

int rand01(void) { 
    return rand() % 2; 
}

int randBetween(int num){ 
    return rand() % num + 1; 
}

int main(){
    srand(time(NULL));
    struct Stack stack;
    initializeStack(&stack);

    for(int i = 0; i < 15; i++){
        int rnd = rand01();
        int rndVal = randBetween(100);
        
        if(rnd % 2 == 0) push(&stack, rndVal);
        else pop(&stack);
    }

    displayStack(&stack);
    return 0;   
}