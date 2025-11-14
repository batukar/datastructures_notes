#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 40
#define START 20

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void sumAndCount(struct Node* root, int* sum, int* count) {
    if (root == NULL) return;
    *sum += root->data;
    (*count)++;
    sumAndCount(root->left, sum, count);
    sumAndCount(root->right, sum, count);
}

void evenOdd(struct Node* root, int* even, int* odd) {
    if (root == NULL) return;
    if (root->data % 2 == 0) (*even)++;
    else (*odd)++;
    evenOdd(root->left, even, odd);
    evenOdd(root->right, even, odd);
}

int leafCount(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return leafCount(root->left) + leafCount(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    srand(time(NULL));
    struct Node* root = NULL;
    int num, sum, count, even, odd, leaf;

    sum = count = even = odd = 0;

    printf("Eklenen elemanlar:\n");
    for (int i = 0; i < SIZE; i++) {
        num = rand() % START + 1;
        printf("%d ", num);
        root = insert(root, num);
    }

    printf("\n\n");
    printf("Inorder (from-Min-To-Max):\n");
    inorder(root);
    printf("\n\n");

    sumAndCount(root, &sum, &count);
    evenOdd(root, &even, &odd);
    leaf = leafCount(root);

    printf("Toplam dugum sayisi: %d\n", count);
    printf("Aritmetik ortalama: %.2f\n", (float)sum / count);
    printf("Cift sayilar: %d\n", even);
    printf("Tek sayilar: %d\n", odd);
    printf("Yaprak dugum sayisi: %d\n", leaf);

    return 0;
}
