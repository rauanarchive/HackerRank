 #include <assert.h>
 #include <limits.h>
 #include <math.h>
 #include <stdbool.h>
 #include <stddef.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
int* prefix_function(char* s) {
		int n = strlen(s);
		int i;
		int* pi = (int*)malloc(n*sizeof(int));
		for (i=0; i<n; i++) pi[i]=0;
		for (int i = 1; i < n; i++) {
				 int j = pi[i-1];
				 while (j > 0 && s[i] != s[j])
						 j = pi[j-1];
				 if (s[i] == s[j])
						 j++;
				 pi[i] = j;
		 }
		return pi;
}
int check_letter(char c, char* s, int n)
{
		int i;
		for (i=0; i<n; i++)
				if (s[i]==c)
				{
						return 1;
				}
		return 0;
}
void intersection(char* s1, char* s2)
{
		 int* alphabet = (int*) malloc(sizeof(int)*26);
	char c = 'a';
	int i;
		for (i=0; i<26; i++)
				alphabet[i]=0;
		int len1, len2;
		len1 = strlen(s1);
		len2 = strlen(s2);
		// looking up what letters are in s1 and s2
		for (i=0; i<26; i++)
		{
				alphabet[i]= check_letter(c+i,s1,len1)*check_letter(c+i,s2,len2);
		}
		for (i=0; i<26; i++)
		{
				printf("%c - %i\n ",c+i,alphabet[i]);
		}
		free(alphabet);
}
void display_array(int* array, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%i",array[i]);
	}
	printf("\n");
	char c = 'a';
	for (i=0; i<26; i++)
		printf("%c",c+i);
	return;
}
int main()
{
	char* pattern = "ababaca";
	int* l;
	l = prefix_function(pattern);
	display_array(l,7);
	intersection("hello","world");
	return 0;
}
