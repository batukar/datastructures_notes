#include <stdio.h>
#include <stdlib.h>

// Veri Yapisi
typedef struct Node{
    int key;
    struct Node *right, *left;
} Node;

int menu();
Node* newNode(int key);
Node* insertNode(Node* root, int key);
Node* minNode(Node* root);
Node* maxNode(Node* root);
Node* searchNode(Node* root, int key);
Node* deleteNode(Node* root, int key);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);

Node* newNode(int key){
    Node* new = (Node*)malloc(sizeof(Node));
    new->key = key;
    new->right = new->left = NULL;

    return new;
}

Node* insertNode(Node* root, int key){
    if(!root) return newNode(key);

    if(key < root->key){
        root->left = insertNode(root->left, key);
    }else if(key > root->key){
        root->right = insertNode(root->right, key);
    }
    return root;
}

Node* minNode(Node* root){
    if(!root) return NULL;

    while(root->left){
        root = root->left;
    }
    return root;
}

Node* maxNode(Node* root){
    if(!root) return NULL;
    
    while(root->right){
        root = root->right;
    }
    return root;
}

Node* searchNode(Node* root, int key){
    while(root){
        if(key == root->key){
            return root;
        }
        root = (key < root->key) ? root->left : root->right;
    }
    return NULL;
}

Node* deleteNode(Node* root, int key){
    if(!root) return NULL;

    if(key < root->key){
        root->left = deleteNode(root->left, key);
    }else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }else{ // dugumu bulduk
        if(root->left == NULL){
            Node* r = root->right;
            free(root);
            return r;
        }else if(root->right == NULL){
            Node* l = root->left;
            free(root);
            return l;
        }
        Node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(Node* root){
    if(!root) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

int menu(){
    int choice;
    printf("\n~~~~BST Menu ~~~~\n");
    printf("1. Dugum Ekleme\n");
    printf("2. En Kucuk Dugumu Bulma\n");
    printf("3. En Buyuk Dugumu Bulma\n");
    printf("4. Dugum Arama\n");
    printf("5. Dugum Silme\n");
    printf("6. Agacı Goruntule\n");
    printf("7. Agacta Dolasim\n");
    printf("8. Cikis\n");
    printf("Secim yapiniz: \n");
    scanf("%d", &choice);

    return choice;
}

int main(){
    Node * root = NULL;
    
    for(;;){
    int m = menu();
        switch (m){
            case 1: // dugum ekleme
                int value;
                printf("Dugum giriniz: \n");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2: // min dugum
                Node* min = minNode(root);
                if(min) printf("En kucuk dugum: %d\n", min->key);
                else printf("Agac bos!\n");
                break;
            case 3: // max dugum
                Node* max = maxNode(root);
                if(max) printf("En buyuk dugum: %d\n", max->key);
                else printf("Agac bos!\n");
                break;
            case 4: // dugum arama
                int srch;
                printf("Aranacak dugumu girin: \n");
                scanf("%d", &srch);
                Node* search = searchNode(root, srch);
                if(search) printf("Bulundu: %d\n", search->key);
                else printf("Bulunamadi: %d\n", srch); 
                break;
            case 5: // dugum silme
                int del;
                printf("Silinecek dugum girin: \n");
                scanf("%d", &del);
                if(!searchNode(root, del)){
                    printf("Dugum bulunamadi: %d\n", del);
                }else printf("Dugum siliniyor: %d\n", del);
                root = deleteNode(root, del);
                break;
            case 6: // inorder
                inorder(root);
                printf("\n");
                break;
            case 7: // traversal
                int tra;
                
                printf("\n~~~~Dolasim Menusu~~~~\n");
                printf("1. inorder\n");
                printf("2. preorder\n");
                printf("3. postorder\n");
                printf("Secim yapiniz: \n");
                scanf("%d", &tra);

                switch (tra){
                    case 1: // inorder
                        inorder(root);
                        printf("\n");
                        continue;
                    case 2: // preorder
                        preorder(root);
                        printf("\n");
                        continue;
                    case 3: // postorder
                        postorder(root);
                        printf("\n");
                        continue;
                    default:
                        printf("Gecersiz secim yapildi!\n");
                        continue;
                }
            case 8: // cikis
                printf("Cikis yapiliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim yapildi!\n");
                break;
        }
    }

    return 0;
}