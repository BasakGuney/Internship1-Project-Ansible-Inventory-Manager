#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *reverse(char *input)
{
    int len = strlen(input);
    char *output=malloc(len+1);
    output[len]='\0';
    for (int i = 0; i < len; i++) {
    output[len - i - 1] = input[i];
}
 return output;
}

int main(){
    printf("1- In reverse function there is a local variable defined as \"output\" which is located in stack memory.\n   When you go back to the main function local variables are deallocated therefore the function returns null.\n   to fix this bug we can allocate place from heap with malloc() function.\n");
    printf("2- After fixing the first bug, strlen function ignores terminating null character\n   so null character won't added to the end of the output then you will not get the expected string.\n");
    printf("Enter a string with maximum length 0f 100:\n");
    char str[100];
    fgets(str,100,stdin);
    printf("%s",reverse(str));
    return 0;
}