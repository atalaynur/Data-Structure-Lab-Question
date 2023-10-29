#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    char surname[50];
    int number;
};

void addStudent(struct student *studentList, int *studentCount, const char *name, const char *surname, int number) {
    if (*studentCount < 50) { // maksimum 50 öğrenci
        strcpy(studentList[*studentCount].name, name);
        strcpy(studentList[*studentCount].surname, surname);
        studentList[*studentCount].number = number;
        (*studentCount)++;
    } else {
        printf("Maximum student limit reached!\n");
    }
}

void searchStudent(const struct student *studentList, int studentCount, const char *searchName) {
    int found = 0;
    
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(searchName, studentList[i].name) == 0) {
            printf("Name: %s, Surname: %s, Number: %d\n", studentList[i].name, studentList[i].surname, studentList[i].number);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    struct student studentList[50];
    int studentCount = 0;
    
    // öğrenci ekleme
    int choice;
    char name[50], surname[50];
    int number;
    
    while (1) {
        printf("1. Add Student\n2. Search Student\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Name: ");
            scanf("%s", name);
            printf("Surname: ");
            scanf("%s", surname);
            printf("Number: ");
            scanf("%d", &number);
            addStudent(studentList, &studentCount, name, surname, number);
        } else if (choice == 2) {
            printf("Search Student Name: ");
            scanf("%s", name);
            searchStudent(studentList, studentCount, name);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    
    return 0;
}