#include "string_ops.h"

/**
* 1. create a buffer, size is #define SIZE_OF_BUFFER
*/
char* buff_create()
{
	return ((char*)(malloc(sizeof(char) * SIZE_OF_BUFFER)));
}

/**
* 2. free a buffer
*/
BOOL buff_free(char *buff);

/**
* 3. init the 1st char of buff to "\0"
*/
BOOL buff_clean(char *buff);

/**
* 4. return the size of string, char* str is the original string.
*/
int str_getlen(char* str);

/**
* 5. return the status of buffer (full)
*/
BOOL buff_isfull(char* str);

/**
* 6. return the status of buffer (empty)
*/
BOOL buff_isempty(char* str);

/**
* 7. return the first location of char or the first char of substring
*/
int str_getlocation(char* str, char* substr);

/**
* 8. insert a char or a substring to the string
*/
char* str_insert(char* str, char* substr, int index);

/**
* 9. delete all of the char or the substring from the string
*/
char* str_del(char* str, char* substr);

/**
* 10. replace all of the char or the substring with another in the string
*/
char* str_replace(char* str, char* rep, char* origin);

/**
* 11. sort of string(from small to big with ASCII code)
*/
char* str_sort(char* str);

/**
* 12. return the times of a substring repeat in a string
*/
int str_rep(char* str, char* substr);


