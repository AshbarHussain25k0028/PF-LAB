#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student {
    int student_id;
    char full_name[100];
    char batch[32];
    char membership_type[16];
    char registration_date[16];
    char date_of_birth[16];
    char interest_in[16];
};

struct Student *database = NULL;
int total_students = 0;

int check_int() {
    int x;
    while (scanf("%d", &x) != 1) {
        printf("Wrong input. Write a number: ");
        while (getchar() != '\n');
    }
    return x;
}

int check_date(const char *d) {
    if (strlen(d) != 10) return 0;
    if (d[4] != '-' || d[7] != '-') return 0;
    int i;
    for (i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(d[i])) return 0;
    }
    return 1;
}

int check_batch(const char *b) {
    if (strcmp(b, "CS") == 0) return 1;
    if (strcmp(b, "SE") == 0) return 1;
    if (strcmp(b, "CyberSecurity") == 0) return 1;
    if (strcmp(b, "AI") == 0) return 1;
    return 0;
}

int check_membership(const char *m) {
    if (strcmp(m, "IEEE") == 0) return 1;
    if (strcmp(m, "ACM") == 0) return 1;
    return 0;
}

int check_interest(const char *i) {
    if (strcmp(i, "IEEE") == 0) return 1;
    if (strcmp(i, "ACM") == 0) return 1;
    if (strcmp(i, "Both") == 0) return 1;
    return 0;
}

void loadDatabase(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return;
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    total_students = size / sizeof(struct Student);
    if (total_students > 0) {
        database = malloc(total_students * sizeof(struct Student));
        fread(database, sizeof(struct Student), total_students, file);
    }
    fclose(file);
}

int saveDatabase(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) return -1;
    fwrite(database, sizeof(struct Student), total_students, file);
    fclose(file);
    return 0;
}

int findStudent(int id) {
    int i;
    for (i = 0; i < total_students; i++) {
        if (database[i].student_id == id) return i;
    }
    return -1;
}

int addStudent(struct Student s, const char *filename) {
    if (findStudent(s.student_id) != -1) return -1;
    database = realloc(database, (total_students + 1) * sizeof(struct Student));
    database[total_students] = s;
    total_students++;
    saveDatabase(filename);
    return 0;
}

int updateStudent(int id, const char *filename) {
    int i = findStudent(id);
    if (i == -1) return -1;

    char new_batch[32];
    char new_membership[16];

    printf("Write new batch (CS / SE / CyberSecurity / AI): ");
    scanf("%31s", new_batch);
    while (!check_batch(new_batch)) {
        printf("Wrong batch. Try again: ");
        scanf("%31s", new_batch);
    }
    strncpy(database[i].batch, new_batch, sizeof(database[i].batch));

    printf("Write new membership (IEEE / ACM): ");
    scanf("%15s", new_membership);
    while (!check_membership(new_membership)) {
        printf("Wrong membership. Try again: ");
        scanf("%15s", new_membership);
    }
    strncpy(database[i].membership_type, new_membership, sizeof(database[i].membership_type));

    saveDatabase(filename);
    return 0;
}

int deleteStudent(int id, const char *filename) {
    int i = findStudent(id);
    if (i == -1) return -1;

    int j;
    for (j = i; j < total_students - 1; j++) {
        database[j] = database[j + 1];
    }

    total_students--;
    database = realloc(database, total_students * sizeof(struct Student));
    saveDatabase(filename);
    return 0;
}

void showAllStudents() {
    int i;
    if (total_students == 0) {
        printf("No students found\n");
        return;
    }

    for (i = 0; i < total_students; i++) {
        printf("\nStudent ID: %d\n", database[i].student_id);
        printf("Name: %s\n", database[i].full_name);
        printf("Batch: %s\n", database[i].batch);
        printf("Membership: %s\n", database[i].membership_type);
        printf("Reg Date: %s\n", database[i].registration_date);
        printf("DOB: %s\n", database[i].date_of_birth);
        printf("Interest: %s\n", database[i].interest_in);
    }
}

void batchReport() {
    char b[32];
    printf("Write batch to search: ");
    scanf("%31s", b);

    if (!check_batch(b)) {
        printf("Wrong batch\n");
        return;
    }

    int i, found = 0;
    for (i = 0; i < total_students; i++) {
        if (strcmp(database[i].batch, b) == 0) {
            found = 1;
            printf("\nStudent ID: %d\n", database[i].student_id);
            printf("Name: %s\n", database[i].full_name);
            printf("Membership: %s\n", database[i].membership_type);
        }
    }

    if (!found) printf("No students in this batch\n");
}

int main() {
    const char *filename = "members.dat";
    loadDatabase(filename);

    int choice;
    while (1) {
        printf("\n--- Student Membership Menu ---\n");
        printf("1. Add student\n");
        printf("2. Update student\n");
        printf("3. Delete student\n");
        printf("4. Show all\n");
        printf("5. Batch report\n");
        printf("6. Exit\n");
        printf("Your choice: ");

        choice = check_int();

        if (choice == 1) {
            struct Student s;

            printf("Write student id: ");
            s.student_id = check_int();

            if (findStudent(s.student_id) != -1) {
                printf("This id already exists\n");
                continue;
            }

            printf("Write full name: ");
            scanf(" %[^\n]", s.full_name);
            while (strlen(s.full_name) < 2) {
                printf("Name too short. Write again: ");
                scanf(" %[^\n]", s.full_name);
            }

            printf("Write batch (CS / SE / CyberSecurity / AI): ");
            scanf("%31s", s.batch);
            while (!check_batch(s.batch)) {
                printf("Wrong batch. Try again: ");
                scanf("%31s", s.batch);
            }

            printf("Write membership (IEEE / ACM): ");
            scanf("%15s", s.membership_type);
            while (!check_membership(s.membership_type)) {
                printf("Wrong membership. Try again: ");
                scanf("%15s", s.membership_type);
            }

            printf("Write registration date (YYYY-MM-DD): ");
            scanf("%15s", s.registration_date);
            while (!check_date(s.registration_date)) {
                printf("Bad date. Write again: ");
                scanf("%15s", s.registration_date);
            }

            printf("Write date of birth (YYYY-MM-DD): ");
            scanf("%15s", s.date_of_birth);
            while (!check_date(s.date_of_birth)) {
                printf("Bad date. Write again: ");
                scanf("%15s", s.date_of_birth);
            }

            printf("Write interest (IEEE / ACM / Both): ");
            scanf("%15s", s.interest_in);
            while (!check_interest(s.interest_in)) {
                printf("Wrong choice. Try again: ");
                scanf("%15s", s.interest_in);
            }

            if (addStudent(s, filename) == 0)
                printf("Student added\n");
        }

        else if (choice == 2) {
            int id;
            printf("Write id to update: ");
            id = check_int();
            if (updateStudent(id, filename) == 0)
                printf("Student updated\n");
            else
                printf("Student not found\n");
        }

        else if (choice == 3) {
            int id;
            printf("Write id to delete: ");
            id = check_int();
            if (deleteStudent(id, filename) == 0)
                printf("Student deleted\n");
            else
                printf("Student not found\n");
        }

        else if (choice == 4) {
            showAllStudents();
        }

        else if (choice == 5) {
            batchReport();
        }

        else if (choice == 6) {
            saveDatabase(filename);
            printf("Bye\n");
            break;
        }

        else {
            printf("Wrong choice\n");
        }
    }

    free(database);
    return 0;
}

