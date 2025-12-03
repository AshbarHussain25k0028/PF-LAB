#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct EMPLOYEE {
    int ID;
    char NAME[50];
    char ROLE[50];
    float SALARY;
};

int VALIDATE_TEXT(char STR[]) {
    int i = 0;
    if(strlen(STR) == 0) return 0;
    while(STR[i] != '\0') {
        if(!isalpha(STR[i]) && STR[i] != ' ') return 0;
        i++;
    }
    return 1;
}

void DISPLAY_EMPLOYEES(struct EMPLOYEE ARR[], int COUNT) {
    int I = 0;
    printf("\nHere are all the employees entered:\n");
    for(I = 0; I < COUNT; I++) {
        printf("\nEmployee %d:\n", I + 1);
        printf("ID: %d\n", ARR[I].ID);
        printf("Name: %s\n", ARR[I].NAME);
        printf("Designation: %s\n", ARR[I].ROLE);
        printf("Salary: %.2f\n", ARR[I].SALARY);
    }
}

void FIND_HIGHEST_SALARY(struct EMPLOYEE ARR[], int COUNT) {
    int I = 0;
    int BEST = 0;
    for(I = 1; I < COUNT; I++) {
        if(ARR[I].SALARY > ARR[BEST].SALARY) BEST = I;
    }
    printf("\nEmployee with the highest salary:\n");
    printf("ID: %d\n", ARR[BEST].ID);
    printf("Name: %s\n", ARR[BEST].NAME);
    printf("Designation: %s\n", ARR[BEST].ROLE);
    printf("Salary: %.2f\n", ARR[BEST].SALARY);
}

void SEARCH_EMPLOYEE(struct EMPLOYEE ARR[], int COUNT) {
    int CHOICE, I = 0, FOUND = 0;
    char LOOK_NAME[50];
    int LOOK_ID;
    printf("\nHow would you like to search?\n1. By ID\n2. By Name\nEnter option: ");
    scanf("%d", &CHOICE);
    getchar();

    switch(CHOICE) {
        case 1:
            FOUND = 0;
            printf("Enter the ID you want to search: ");
            scanf("%d", &LOOK_ID);
            getchar();
            for(I = 0; I < COUNT; I++) {
                if(ARR[I].ID == LOOK_ID) {
                    FOUND = 1;
                    printf("\nEmployee found:\n");
                    printf("ID: %d\n", ARR[I].ID);
                    printf("Name: %s\n", ARR[I].NAME);
                    printf("Designation: %s\n", ARR[I].ROLE);
                    printf("Salary: %.2f\n", ARR[I].SALARY);
                    break;
                }
            }
            if(FOUND == 0) printf("\nNo employee found with ID %d.\n", LOOK_ID);
            break;

        case 2:
            FOUND = 0;
            printf("Enter the name you want to search: ");
            fgets(LOOK_NAME, sizeof(LOOK_NAME), stdin);
            LOOK_NAME[strcspn(LOOK_NAME, "\n")] = '\0';
            for(I = 0; I < COUNT; I++) {
                if(strcmp(ARR[I].NAME, LOOK_NAME) == 0) {
                    FOUND = 1;
                    printf("\nEmployee found:\n");
                    printf("ID: %d\n", ARR[I].ID);
                    printf("Name: %s\n", ARR[I].NAME);
                    printf("Designation: %s\n", ARR[I].ROLE);
                    printf("Salary: %.2f\n", ARR[I].SALARY);
                    break;
                }
            }
            if(FOUND == 0) printf("\nNo employee found with the name %s.\n", LOOK_NAME);
            break;

        default:
            printf("\nInvalid option selected.\n");
    }
}

void GIVE_BONUS(struct EMPLOYEE ARR[], int COUNT, float LIMIT) {
    int I = 0;
    for(I = 0; I < COUNT; I++) {
        if(ARR[I].SALARY < LIMIT) ARR[I].SALARY += (ARR[I].SALARY * 0.10);
    }
}

int main() {
    int COUNT, I = 0, TEMPID;
    char TEMPSTR[50];
    printf("Enter how many employees you want to add: ");
    while(scanf("%d", &COUNT) != 1 || COUNT <= 0) {
        printf("Invalid input. Enter a positive number: ");
        while(getchar() != '\n');
    }
    getchar();

    struct EMPLOYEE EMP[COUNT];

    for(I = 0; I < COUNT; I++) {
        printf("\nEmployee %d details:\n", I + 1);

        while(1) {
            printf("Enter ID: ");
            if(scanf("%d", &TEMPID) == 1 && TEMPID > 0) {
                EMP[I].ID = TEMPID;
                getchar();
                break;
            } else {
                printf("Invalid input. ID must be a positive number.\n");
                while(getchar() != '\n');
            }
        }

        while(1) {
            printf("Enter Name: ");
            fgets(TEMPSTR, sizeof(TEMPSTR), stdin);
            TEMPSTR[strcspn(TEMPSTR, "\n")] = '\0';
            if(VALIDATE_TEXT(TEMPSTR)) {
                strcpy(EMP[I].NAME, TEMPSTR);
                break;
            } else {
                printf("Invalid input. Name must contain only letters and spaces.\n");
            }
        }

        while(1) {
            printf("Enter Designation: ");
            fgets(TEMPSTR, sizeof(TEMPSTR), stdin);
            TEMPSTR[strcspn(TEMPSTR, "\n")] = '\0';
            if(VALIDATE_TEXT(TEMPSTR)) {
                strcpy(EMP[I].ROLE, TEMPSTR);
                break;
            } else {
                printf("Invalid input. Designation must contain only letters and spaces.\n");
            }
        }

        printf("Enter Salary: ");
        while(scanf("%f", &EMP[I].SALARY) != 1 || EMP[I].SALARY < 0) {
            printf("Invalid input. Salary must be a positive number: ");
            while(getchar() != '\n');
        }
        getchar();
    }

    DISPLAY_EMPLOYEES(EMP, COUNT);
    FIND_HIGHEST_SALARY(EMP, COUNT);
    SEARCH_EMPLOYEE(EMP, COUNT);
    GIVE_BONUS(EMP, COUNT, 50000);

    return 0;
}


