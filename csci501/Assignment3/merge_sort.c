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

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    FILE* inFile = fopen(filename, "r");

    int num_digits = get_num_digits(inFile);
    int *array = initialize_array(num_digits);

    populate_array(inFile, num_digits, array);

    merge_sort(array, 0, num_digits - 1);

    print_array(array, num_digits);
    return 0;
}
