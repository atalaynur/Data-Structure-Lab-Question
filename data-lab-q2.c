#include <stdio.h>
#include <stdlib.h>

//Q2 

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

// Liste içeriğini yazdıran fonksiyon
void printlist(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Düğümü sıralı bir şekilde liste içine ekleyen fonksiyon
void siraliEkle(struct Node** head, int value) {
    struct Node* new_node = newNode(value);
    
    if (*head == NULL || value > (*head)->data) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data > value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    struct Node* list = NULL;
    int number;
    int i;

    // Rastgele 100 sayı ekleme
    for (i = 0; i < 100; i++) {
        number = rand() % 100; // 0-999 rastgele sayı üretme
        siraliEkle(&list, number);
    }

    // sıralı listeyi ekrana yazdırır
    printf(":");
    printlist(list);

    // belleği temizler
    while (list != NULL) {
        struct Node* temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}