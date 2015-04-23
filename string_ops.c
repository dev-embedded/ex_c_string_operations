#include "string_ops.h"

/**
* create a buffer, size is #define SIZE_OF_BUFFER
*/
char* buff_create();
/**
* free a buffer
*/
BOOL buff_free(char *buff);

/**
* init the 1st char of buff to "\0"
*/
BOOL buff_clean(char *buff);

/**
* return the size of string, char* str is the original string.
*/
int str_getlen(char* str);

/**
* return the status of buffer (full)
*/
BOOL buff_isfull(char* str);

/**
* return the status of buffer (empty)
*/
BOOL buff_isempty(char* str);

/**
* return the first location of char or the first char of substring
*/
int str_getlocation(char* str, char* substr);

/**
* insert a char or a substring to the string
*/
char* str_insert(char* str, char* substr, int index);

/**
* delete all of the char or the substring from the string
*/
char* str_del(char* str, char* substr);

/**
* replace all of the char or the substring with another in the string
*/
char* str_replace(char* str, char* rep, char* origin);

/**
* sort of string(from small to big with ASCII code)
*/
char* str_sort(char* str);

/**
* return the times of a substring repeat in a string
*/
int str_rep(char* str, char* substr);


