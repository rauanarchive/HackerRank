#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the bomberMan function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//
char** bomberMan(int n, int grid_count, char** grid, int* result_count) {

*result_count = 2;
int i,j;
printf("in the bomberMan\n");

printf("n=%i\n",n);
printf("grid_count = %i\n",grid_count);

for (i=0; i<grid_count; i++)
{
  for (j=0; j<grid_count; j++)
  {
    printf("%c ",grid[i][j]);
  }
  printf("\n");
}
return NULL;

}

int main()
{
    // FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** rcn = split_string(readline());

    char* r_endptr;
    char* r_str = rcn[0];
    int r = strtol(r_str, &r_endptr, 10);

    if (r_endptr == r_str || *r_endptr != '\0') { exit(EXIT_FAILURE); }

    char* c_endptr;
    char* c_str = rcn[1];
    int c = strtol(c_str, &c_endptr, 10);

    if (c_endptr == c_str || *c_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n_endptr;
    char* n_str = rcn[2];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** grid = malloc(r * sizeof(char*));

    for (int i = 0; i < r; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    int grid_count = r;

    int result_count;
    char** result = bomberMan(n, grid_count, grid, &result_count);
    printf("66\n");
    for (int i = 0; i < result_count; i++) {
        // fprintf(fptr, "%s", *(result + i));
        // printf("%s", *(result + i));

        if (i != result_count - 1) {
            // fprintf(fptr, "\n");
            printf("\n");
        }
    }

    // fprintf(fptr, "\n");
    printf("\n");

    // fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
