#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the timeConversion function below.
 */

/*
 * Please either make the string static or allocate on the heap. For example,
 * static char str[] = "hello world";
 * return str;
 *
 * OR
 *
 * char* str = "hello world";
 * return str;
 *
 */
char* timeConversion(char* s) {

    static char midtime[] = "12:00:00";
    // not static, but heap variable AMP




    if ((s[8]=='A')&&(s[9]=='M'))
    {
        //erasing last two characters
        s[8]=s[9]=0;

        if (!strcmp(s,midtime))
        {

            return "00:00:00";
        }
        //replace hh by 00
        if ((s[0]=='1')&&(s[1]=='2'))
        {
          s[0]='0';
          s[1]='0';
        }
    }

    if ((s[8]=='P')&&(s[9]=='M'))
    {

      //erasing last two characters
      s[8]=s[9]=0;
      if (!strcmp(s,midtime))
      {


        return "12:00:00";
      }
      //adding 12 to hh

      int int_hh = ((int)s[0]-(int)'0')*10+((int)s[1]-(int)'0')*1;
      if (int_hh!=12)
      {
        int_hh+=12; //adding 12 to account for PM;
      }


      s[0]= (int_hh/10)+'0';
      s[1]= (int_hh%10)+'0';

    }
    // printf("%s\n",s);
    return s;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();
    char* result =timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

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
