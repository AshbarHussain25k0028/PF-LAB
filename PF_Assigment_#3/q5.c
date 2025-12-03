#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line_from_stream(FILE *stream)
{
    size_t buffer_capacity = 128;
    size_t buffer_length = 0;
    char *buffer = malloc(buffer_capacity);
    if (buffer == NULL) {
        fprintf(stderr, "Error: memory allocation failed in read_line_from_stream\n");
        exit(EXIT_FAILURE);
    }
    int character;
    while (1) {
        character = fgetc(stream);
        if (character == EOF || character == '\n') {
            break;
        }
        if (buffer_length + 1 >= buffer_capacity) {
            size_t new_capacity = buffer_capacity * 2;
            char *new_buffer = realloc(buffer, new_capacity);
            if (new_buffer == NULL) {
                free(buffer);
                fprintf(stderr, "Error: memory reallocation failed in read_line_from_stream\n");
                exit(EXIT_FAILURE);
            }
            buffer = new_buffer;
            buffer_capacity = new_capacity;
        }
        buffer[buffer_length++] = (char)character;
    }
    buffer[buffer_length] = '\0';
    char *exact_buffer = realloc(buffer, buffer_length + 1);
    if (exact_buffer == NULL) {
        free(buffer);
        fprintf(stderr, "Error: memory reallocation failed in read_line_from_stream\n");
        exit(EXIT_FAILURE);
    }
    return exact_buffer;
}

int insertLine(int index, const char *text, char ***lines_array_ptr, int *line_count_ptr, int *capacity_ptr)
{
    char **lines_array = *lines_array_ptr;
    int line_count = *line_count_ptr;
    int capacity = *capacity_ptr;
    if (index < 0 || index > line_count) {
        printf("Invalid index. Valid range is 0 to %d\n", line_count);
        return -1;
    }
    if (line_count + 1 > capacity) {
        int new_capacity = (capacity == 0) ? 4 : capacity * 2;
        char **new_array = realloc(lines_array, new_capacity * sizeof(char *));
        if (new_array == NULL) {
            fprintf(stderr, "Error: memory reallocation failed in insertLine\n");
            exit(EXIT_FAILURE);
        }
        lines_array = new_array;
        *lines_array_ptr = lines_array;
        *capacity_ptr = new_capacity;
        capacity = new_capacity;
    }
    if (index < line_count) {
        memmove(&lines_array[index + 1], &lines_array[index], (size_t)(line_count - index) * sizeof(char *));
    }
    size_t text_length = strlen(text);
    char *copy = malloc(text_length + 1);
    if (copy == NULL) {
        fprintf(stderr, "Error: memory allocation failed in insertLine\n");
        exit(EXIT_FAILURE);
    }
    strcpy(copy, text);
    lines_array[index] = copy;
    *line_count_ptr = line_count + 1;
    return 0;
}

int deleteLine(int index, char ***lines_array_ptr, int *line_count_ptr, int *capacity_ptr)
{
    char **lines_array = *lines_array_ptr;
    int line_count = *line_count_ptr;
    if (index < 0 || index >= line_count) {
        printf("Invalid index. Valid range is 0 to %d\n", line_count - 1);
        return -1;
    }
    free(lines_array[index]);
    if (index < line_count - 1) {
        memmove(&lines_array[index], &lines_array[index + 1], (size_t)(line_count - index - 1) * sizeof(char *));
    }
    *line_count_ptr = line_count - 1;
    if (*line_count_ptr == 0) {
        free(lines_array);
        *lines_array_ptr = NULL;
        *capacity_ptr = 0;
    }
    return 0;
}

void printAllLines(char **lines_array, int line_count)
{
    if (line_count == 0) {
        printf("[Buffer is empty]\n");
        return;
    }
    int index;
    for (index = 0; index < line_count; index++) {
        printf("%d: %s\n", index, lines_array[index]);
    }
}

void freeAll(char **lines_array, int line_count)
{
    int index;
    for (index = 0; index < line_count; index++) {
        free(lines_array[index]);
    }
    free(lines_array);
}

int shrinkToFit(char ***lines_array_ptr, int *capacity_ptr, int line_count)
{
    char **lines_array = *lines_array_ptr;
    if (line_count == 0) {
        free(lines_array);
        *lines_array_ptr = NULL;
        *capacity_ptr = 0;
        return 0;
    }
    char **new_array = realloc(lines_array, (size_t)line_count * sizeof(char *));
    if (new_array == NULL) {
        fprintf(stderr, "Error: memory reallocation failed in shrinkToFit\n");
        exit(EXIT_FAILURE);
    }
    *lines_array_ptr = new_array;
    *capacity_ptr = line_count;
    return 0;
}

int saveToFile(const char *file_path, char **lines_array, int line_count)
{
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        printf("Error: cannot open file for writing: %s\n", file_path);
        return -1;
    }
    int index;
    for (index = 0; index < line_count; index++) {
        if (fprintf(file, "%s\n", lines_array[index]) < 0) {
            printf("Error: failed to write to file: %s\n", file_path);
            fclose(file);
            return -1;
        }
    }
    fclose(file);
    return 0;
}

int loadFromFile(const char *file_path, char ***lines_array_ptr, int *line_count_ptr, int *capacity_ptr)
{
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: cannot open file for reading: %s\n", file_path);
        return -1;
    }
    char **new_array = NULL;
    int new_capacity = 0;
    int new_line_count = 0;
    char *line_text;
    while (1) {
        int next_char = fgetc(file);
        if (next_char == EOF) {
            break;
        }
        ungetc(next_char, file);
        line_text = read_line_from_stream(file);
        if (new_line_count + 1 > new_capacity) {
            int target_capacity = (new_capacity == 0) ? 4 : new_capacity * 2;
            char **resized = realloc(new_array, (size_t)target_capacity * sizeof(char *));
            if (resized == NULL) {
                fprintf(stderr, "Error: memory reallocation failed in loadFromFile\n");
                free(line_text);
                if (new_array) {
                    int i;
                    for (i = 0; i < new_line_count; i++) free(new_array[i]);
                    free(new_array);
                }
                fclose(file);
                exit(EXIT_FAILURE);
            }
            new_array = resized;
            new_capacity = target_capacity;
        }
        new_array[new_line_count++] = line_text;
    }
    fclose(file);
    if (*lines_array_ptr != NULL && *line_count_ptr > 0) {
        freeAll(*lines_array_ptr, *line_count_ptr);
    } else if (*lines_array_ptr != NULL) {
        free(*lines_array_ptr);
    }
    *lines_array_ptr = new_array;
    *line_count_ptr = new_line_count;
    *capacity_ptr = new_capacity;
    return 0;
}

int main()
{
    char **lines_array = NULL;
    int capacity = 0;
    int line_count = 0;
    while (1) {
        printf("\nSimple Line Editor - choose an option:\n");
        printf("1) insert\n");
        printf("2) delete\n");
        printf("3) print\n");
        printf("4) save\n");
        printf("5) load\n");
        printf("6) shrink\n");
        printf("7) free and exit\n");
        printf("Enter option number: ");
        int option;
        if (scanf("%d", &option) != 1) {
            printf("Invalid input\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            continue;
        }
        int index_value;
        char file_path[512];
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        if (option == 1) {
            printf("Enter index to insert at (0 to %d): ", line_count);
            if (scanf("%d", &index_value) != 1) {
                printf("Invalid index input\n");
                while ((c = getchar()) != '\n' && c != EOF) { }
                continue;
            }
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Enter text for new line: ");
            char *text_line = read_line_from_stream(stdin);
            int res = insertLine(index_value, text_line, &lines_array, &line_count, &capacity);
            free(text_line);
            if (res == 0) printf("Line inserted\n");
        } else if (option == 2) {
            if (line_count == 0) {
                printf("Buffer is empty, nothing to delete\n");
                continue;
            }
            printf("Enter index to delete (0 to %d): ", line_count - 1);
            if (scanf("%d", &index_value) != 1) {
                printf("Invalid index input\n");
                while ((c = getchar()) != '\n' && c != EOF) { }
                continue;
            }
            while ((c = getchar()) != '\n' && c != EOF) { }
            int res = deleteLine(index_value, &lines_array, &line_count, &capacity);
            if (res == 0) printf("Line deleted\n");
        } else if (option == 3) {
            printAllLines(lines_array, line_count);
        } else if (option == 4) {
            printf("Enter file path to save to: ");
            if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
                printf("Invalid input\n");
                continue;
            }
            size_t len = strlen(file_path);
            if (len > 0 && file_path[len - 1] == '\n') file_path[len - 1] = '\0';
            int res = saveToFile(file_path, lines_array, line_count);
            if (res == 0) printf("Saved to %s\n", file_path);
        } else if (option == 5) {
            printf("Enter file path to load from: ");
            if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
                printf("Invalid input\n");
                continue;
            }
            size_t len = strlen(file_path);
            if (len > 0 && file_path[len - 1] == '\n') file_path[len - 1] = '\0';
            int res = loadFromFile(file_path, &lines_array, &line_count, &capacity);
            if (res == 0) printf("Loaded %d lines from %s\n", line_count, file_path);
        } else if (option == 6) {
            shrinkToFit(&lines_array, &capacity, line_count);
            printf("Shrink to fit done. Capacity is now %d\n", capacity);
        } else if (option == 7) {
            if (lines_array != NULL && line_count > 0) {
                freeAll(lines_array, line_count);
            } else if (lines_array != NULL) {
                free(lines_array);
            }
            printf("Exiting. Freed memory.\n");
            break;
        } else {
            printf("Unknown option\n");
        }
    }
    return 0;
}

