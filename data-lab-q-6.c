#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// öğrenci yapısı
struct Student {
    char name[50];
    struct Student* next;
};

// Yeni öğrenci düğümü oluşturan fonksiyon
struct Student* createStudent(const char* name) {
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    strcpy(student->name, name);
    student->next = NULL;
    return student;
}

// Yeni öğrenci düğümünü listenin başına ekleyen fonksiyon
struct Student* addStudent(struct Student* start, const char* name) {
    struct Student* newStudent = createStudent(name);
    newStudent->next = start;
    return newStudent;
}

// En uzun ismi ve uzunluğunu bulan fonksiyon
void findLongestNamedStudent(const struct Student* start) {
    const struct Student* current = start;
    const char* longestName = NULL;
    size_t longestLength = 0;

    while (current != NULL) {
        size_t length = strlen(current->name);
        if (length > longestLength) {
            longestLength = length;
            longestName = current->name;
        }
        current = current->next;
    }

    if (longestName != NULL) {
        printf("Longest name: %s\n", longestName);
        printf("Length: %zu\n", longestLength);
    } else {
        printf("The list is empty.\n");
    }
}

int main() {
    struct Student* start = NULL;
    int choice;

    while (1) {
        printf("1. Add Name\n2. Find the Longest Named Student\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                char name[50];
                printf("Name: ");
                scanf("%s", name);
                start = addStudent(start, name);
                break;

            case 2:
                findLongestNamedStudent(start);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}