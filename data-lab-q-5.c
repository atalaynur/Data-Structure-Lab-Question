#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char surname[50];
    int number;
    struct Student *next;
};

// yeni öğrenci oluşturan fonksiyon
struct Student *createStudent(const char *name, const char *surname, int number) {
    struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    strcpy(student->name, name);
    strcpy(student->surname, surname);
    student->number = number;
    student->next = NULL;
    return student;
}

void showList(const struct Student *start) {
    const struct Student *current = start;
    while (current != NULL) {
        printf("Name: %s, Surname: %s, Number: %d\n", current->name, current->surname, current->number);
        current = current->next;
    }
}

// öğrenci düğümü ekleyen fonksiyon
struct Student *addStudent(struct Student *start, const char *name, const char *surname, int number) {
    struct Student *newStudent = createStudent(name, surname, number);
    newStudent->next = start;
    return newStudent;
}

// Verilen adı taşıyan öğrencinin bir sonraki düğümünü silen fonksiyon
struct Student *deleteStudent(struct Student *start, const char *searchName) {
    struct Student *current = start;
    struct Student *previous = NULL;

    while (current != NULL) {
        if (strcmp(searchName, current->name) == 0) {
            if (previous == NULL) {
                // baş düğümü değiştirir
                start = current->next;
            } else {
                // Önceki düğümün sonraki işaretçisini güncelle

                previous->next = current->next;
            }
            free(current); // belleği serbest bırak
            printf("The next node of student with name %s has been deleted.\n", searchName);
            return start;
        }

        previous = current;
        current = current->next;
    }

    printf("Student with name %s not found.\n", searchName);
    return start;
}

int main() {
    struct Student *start = NULL;
    int studentCount;
    char name[50], surname[50];
    int number;
    int choice;

    while (1) {
        printf("1. Add Student\n2. Delete Student\n3. Show List\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Name: ");
                scanf("%s", name);
                printf("Surname: ");
                scanf("%s", surname);
                printf("Number: ");
                scanf("%d", &number);
                start = addStudent(start, name, surname, number);
                break;

            case 2:
                printf("Enter the name of the student you want to delete: ");
                scanf("%s", name);
                start = deleteStudent(start, name);
                break;

            case 3:
                printf("Student List:\n");
                showList(start);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}