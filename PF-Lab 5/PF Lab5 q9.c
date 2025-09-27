#include <stdio.h>
int main() {
    int department, course;
    printf("Select Department:\n");
    printf("1. CS  2. EE  3. BBA\n");
    scanf("%d", &department);
    switch(department) {
        case 1:
            printf("Select CS Course:\n");
            printf("1. Data Structures\n2. Operating Systems\n3. Databases\n");
            scanf("%d", &course);
            switch(course) {
                case 1: printf("You selected Data Structures\n"); break;
                case 2: printf("You selected Operating Systems\n"); break;
                case 3: printf("You selected Databases\n"); break;
                default: printf("Invalid course\n");
            }
            break;
        case 2:
            printf("Select EE Course:\n");
            printf("1. Circuit Analysis  2. Signals and Systems  3. Power Electronics\n");
            scanf("%d", &course);
            switch(course) {
                case 1: printf("You selected Circuit Analysis\n"); break;
                case 2: printf("You selected Signals and Systems\n"); break;
                case 3: printf("You selected Power Electronics\n"); break;
                default: printf("Invalid course\n");
            }
            break;
        case 3:
            printf("Select BBA Course:\n");
            printf("1. Marketing\n2. Finance\n3. Human Resource Management\n");
            scanf("%d", &course);
            switch(course) {
                case 1: printf("You selected Marketing\n"); break;
                case 2: printf("You selected Finance\n"); break;
                case 3: printf("You selected Human Resource Management\n"); break;
                default: printf("Invalid course\n");
            }
            break;
        default:
            printf("Invalid department\n");
    }
    return 0;
}

