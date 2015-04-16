#include "string_ops.h"

/**
* return the size of string
*/
int get_strlen(char* str);

/**
* return the status of buffer (full)
*/
bool isfull_buffer(char* str);

/**
* return the status of buffer (empty)
*/
bool isempty_buffer(char* str);

/**
* return the first location of char or the first char of substring
*/
int get_location_string(char* str, char* substr);

/**
* add a char or a substring to the string
*/
char* add(char* str, char* substr, int index);

/**
* delete all of the char or the substring from the string
*/
char* del(char* str, char* substr);

/**
* replace all of the char or the substring with another in the string
*/
char* replace(char* str, char* rep, char* origin);

/**
* sort of string(from small to big with ASCII code)
*/
char* sort(char* str);

/**
* return the number of recurring substring in the string
*/
int repetition(char* str, char* substr);


