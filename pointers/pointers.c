#include <stdio.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    int index = 0;
    do
    {
        x[index] = y[index];
        index++;
    }
    while(y[index] != '\0');
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    for(int index=0; str[index] != '\0'; index++)
    {
        if(str[index] == c)
        {
            return str+index;
        }
    }
    return (char *) 0;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    for(int pos_sub_str = 0; haystack[pos_sub_str] != '\0'; haystack++)
    {
        int match = 1;
        for(int pos_test = 0; needle[pos_test] != '\0'; pos_test++)
        {
            char char_needle = needle[pos_test];
            char char_haystack = haystack[pos_sub_str+pos_test];
            if(char_needle != char_haystack)
            {
                match = 0;
                break;
            }
        }
        if(match)
        {
            return haystack+pos_sub_str;
        }
    }
    return (char *) 0;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char('hello', 'e');
    char *found_string = find_string('world', "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
