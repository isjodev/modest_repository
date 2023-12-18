#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_num_digits(FILE* fp) {
    int lines = 0;
    while (!feof(fp)) {
        char ch = fgetc(fp);
        if (ch == '\n') {
            lines++;
        }
    }
    rewind(fp);
    return lines;
}

void print_array(int* arr, int len) {
    for (size_t i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}

int* initialize_array(int len) {
    int* array = malloc(sizeof(int) * len);
    return array;
}

int populate_array(FILE* fPtr, int len, int* array) {
   for (int i = 0; fscanf(fPtr, "%d\n", &array[i]) == 1 && i < len; ++i);
   fclose(fPtr);
   return 1;
}

void print_usage(char* arg) {
    printf("usage: %s <file>", arg);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int* arr, int len) {
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    FILE* fPtr = fopen(filename, "r");

    int num_digits = get_num_digits(fPtr);
    int* array = initialize_array(num_digits);

    populate_array(fPtr, num_digits, array);

    insertion_sort(array, num_digits);

    print_array(array, num_digits);
    return 0;
}
