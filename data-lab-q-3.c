#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// öğrenci bilgisini saklayacak düğüm yapısı
struct student {
    int number;
    char name[50];
    int age;
    struct student* next;
};

//yeni bir öğrenci düğümü oluşturur
struct student* newstudent(int number, const char* name, int age) {
    struct student* student = (struct student*)malloc(sizeof(struct student));
    student->number = number;
    strcpy(student->name, name);
    student->age = age;
    student->next = NULL;
    return student;
}

// öğrenci listesini ekrana yazdıran fonksiyon
void printstudentlist(struct student* head) {
    struct student* current = head;
    int count = 1;

    while (current != NULL) {
        printf("%d-%s %d %d\n", current->number, current->name, current->age, count);
        current = current->next;
        count++;
    }
}

int main() {
    struct student* head = NULL;
    struct student* last = NULL;
    int number, age;
    char name[50];
    int count = 1;

    while (1) {
        printf("student number, name, age:\n ");
        scanf("%d", &number);

        if (number == -1) {
            break;
        }

        scanf("%s %d", name, &age);

        struct student* student = newstudent(number, name, age);

        if (head == NULL) {
            head = student;
            last = student;
        } else {
            last->next = student;
            last = student;
        }
    }

    // öğrenci listesini ekrana yazdır ve say
    printstudentlist(head);

    // belleği temizler
    struct student* current = head;
    while (current != NULL) {
        struct student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}