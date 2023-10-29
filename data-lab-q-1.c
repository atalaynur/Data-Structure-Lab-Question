#include <stdio.h>
#include <stdlib.h>

//Q1

// Düğüm yapısı
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturur
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Tek sayıları listenin başına, çift sayıları listenin sonuna ekleyen fonksiyon
void eddEvenOdd(struct Node** head, int value) {
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (value % 2 == 1) { // Tek sayı ise
        newNode->next = *head;
        *head = newNode;
    } else { // çift sayı ise
        if (*head == NULL) { // boş ise
            *head = newNode;
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Liste içeriğini yazdıran fonksiyon
void printlist(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* liste = NULL;
    int sayi;

    printf("enter numbers: \n");
    while (1) {
        scanf("%d", &sayi);
        if (sayi == -1) {
            break;
        }
        eddEvenOdd(&liste, sayi);
    }

   printlist(liste);

    // belleği temizle
    while (liste != NULL) {
        struct Node* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}