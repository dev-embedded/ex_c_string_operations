#ifndef STRING_OPS_H_
#define STRING_OPS_H_


#define SIZE_OF_BUFFER 20
#define STR_SIZE 80    //the max length of a string

#define BOOL int
#define TRUE 1
#define FALSE 0


/**
* 1. create a buffer, size is #define SIZE_OF_BUFFER
*/
char* buff_create();

/**
* 2. free a buffer
*/
void buff_free(char *buff);

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

/**
* 13. compare between two string
*/
BOOL str_compare(char* str, char* substr);

/**
* 14. copy a string from buffer
*/
char* str_copy(char* str);


/**
 * a. to compare two strings, if str1 == str2, return 0;
 *    if str1 > str2, return 1; if str1 < str2, return -1.
 */
int str_cmp(char* str1, char* str2);

/**
 * b. To add two strings, str2 will be add to the end of str1, then return str1.
 *    The excess part outside STR_SIZE will be discarded.
 */
char* str_cat(char* str1, const char* str2);

#endif /* STRING_OPS_H_ */
