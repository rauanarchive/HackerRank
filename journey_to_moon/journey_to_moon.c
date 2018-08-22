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

// Complete the journeyToMoon function below.
void search(int root, int** graph, int n, int* visited);
int journeyToMoon(int n, int astronaut_rows, int astronaut_columns, int** astronaut) {

int** graph = (int**)malloc(sizeof(int*)*n); //adjacency matrix
int i,j; //loop  variables
int counted=0, output=1, unvisited=0; //counting
int* visited = (int*)malloc(sizeof(int)*n); //local visited in component
int* global_visited = (int*)malloc(sizeof(int)*n);
   for (i=0; i<n; i++) {
      global_visited[i]=0;
      visited[i]=0;
   }
   for (i=0; i<n; i++)
   {
      graph[i]=(int*)malloc(sizeof(int)*n);
      //iterating over astronaut_rows
      for (j=0; j<n; j++)
      {
         graph[i][j] = 0;
      }
   }
  //build the graph
  for (j=0; j<astronaut_rows; j++)
  {
     graph[astronaut[j][0]][astronaut[j][1]]=1;
     graph[astronaut[j][1]][astronaut[j][0]]=1;
  }

  //initialize

  //now searching connected components
  unvisited = n;
  while (unvisited>0)
  {
     for (i=0; i<n; i++)
     {
        if (global_visited[i]==0)
        {
           search(i, graph, n, visited);
           for (j=0; j<n; j++)
           {
             printf("visited[%i]=%i\n",j,visited[j]);
           }
           if ((i==2) || (i==3))
           {
              printf("%i-th astronaut\n ",i);
              // for (j=0; j<n; j++)
              // {
              //    printf("visited[%i]=%i\n",j,visited[j]);
              // }
           }
           break;
        }
     }
     for (i=0; i<n; i++)
     {
        printf("global_visited[%i]=%i\n",i,global_visited[i]);
     }
     //how to detect only one vertex in the connected component.
     //remembering the connected component\

     for (i=0; i<2*astronaut_rows; i++)
     {
        if (global_visited[i]>=1)// have been before
        {
           ++global_visited[i];
        }
        if (visited[i]==1) unvisited--;
        global_visited[i]+=visited[i];
        visited[i]=0;
     }

  }
  for (i=1; i<=2*astronaut_rows; i++)
  {
     counted=0;
     for (j=0; j<n; j++)
        if (global_visited[j]==i)
        {
           counted++;
        }
        if (counted) output=output*counted;
  }
    return output;
}
// we store nodes as integers in the range 1..n
//visited stores visit records for each node 1..n
//size of visited is n
//visited is malloced in the function above and freed
void search(int root, int** graph, int n, int* visited)
{

  if (root==-1)
  {
    return;//simulating empty pointer=-1
  }
  //visit(root)

  visited[root]=1;

  int i;

  for (i=0;i<n; i++)
  {
     if (graph[root][i])// if root astronaut is adjacent to i-th astronaut
     {
        if (visited[i]==0) // if i-th astronaut is unvisited
        {
           search(i, graph, n, visited);
        }
      // we already visited it
        search(-1, graph, n, visited);//empty children
     }
  }

  return;
}
int main()
{
    // FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** np = split_string(readline());

    char* n_endptr;
    char* n_str = np[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* p_endptr;
    char* p_str = np[1];
    int p = strtol(p_str, &p_endptr, 10);

    if (p_endptr == p_str || *p_endptr != '\0') { exit(EXIT_FAILURE); }

    int** astronaut = malloc(p * sizeof(int*));

    for (int i = 0; i < p; i++) {
        *(astronaut + i) = malloc(2 * (sizeof(int)));

        char** astronaut_item_temp = split_string(readline());

        for (int j = 0; j < 2; j++) {
            char* astronaut_item_endptr;
            char* astronaut_item_str = *(astronaut_item_temp + j);
            int astronaut_item = strtol(astronaut_item_str, &astronaut_item_endptr, 10);

            if (astronaut_item_endptr == astronaut_item_str || *astronaut_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(astronaut + i) + j) = astronaut_item;
        }
    }

    int astronaut_rows = p;
    int astronaut_columns = 2;

    int result = journeyToMoon(n, astronaut_rows, astronaut_columns, astronaut);

    // fprintf(fptr, "%d\n", result);
    printf("%d\n",result);
    //
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
