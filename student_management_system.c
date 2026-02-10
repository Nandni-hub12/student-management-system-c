#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
    float marks;
};

void addstudent() {
    FILE *fp;
    struct student s;
    fp = fopen("student.txt", "ab");
    if (fp == NULL) {
        printf("file error\n");
        return;
    }

    printf("enter ID: ");
    if (scanf("%d", &s.id) != 1) {
        printf("invalid input\n");
        fclose(fp);
        return;
    }

    printf("enter name: ");
    scanf("%49s", s.name);

    printf("enter marks: ");
    if (scanf("%f", &s.marks) != 1) {
        printf("invalid input\n");
        fclose(fp);
        return;
    }

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("student record added successfully!\n");
}

void displaystudent() {
    FILE *fp;
    struct student s;

    fp = fopen("student.txt", "rb");
    if (fp == NULL) {
        printf("no records found\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        printf("\nID: %d", s.id);
        printf("\nName: %s", s.name);
        printf("\nMarks: %.2f\n", s.marks);
    }
    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n----Student management system----\n");
        printf("1. Add student record\n");
        printf("2. Display student records\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("invalid input\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (choice) {
            case 1:
                addstudent();
                break;
            case 2:
                displaystudent();
                break;
            case 3:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}

