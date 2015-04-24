#include <string.h>
#include "string_ops.h"

/**
 * 1. create a buffer, sfize is #define SIZE_OF_BUFFER
 */
char* buff_create()
{
	return ((char*) (malloc(sizeof(char) * SIZE_OF_BUFFER)));
}

/**
 * 2. free a buffer  (by ZS)
 */
BOOL buff_free(char *buff);{
	//int *ptr = (int*) malloc(*buff); // create a buffer with sizeof buff
	void free(ptr);
}
/**
 * 3. init the 1st char of buff to "\0"
 */
BOOL buff_clean(char *buff);

/**
 * 4. return the size of string, char* str is the original string.
 */
int str_getlen(char* str)
{
	int len = 0;
	while ('\0' != *(str + len))
	{
		len++;
	}
	return len;
}

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
 * 	if return -1 , it means that no find.
 */
int str_getlocation(char* str, char* substr)
{
	int len_str = 0;
	int len_substr = str_getlen(substr);
	BOOL res = FALSE;
	while (('\0' != *(str + len_str)) && !res)
	{
		if (*(substr) == *(str + len_str))
		{
			res = TRUE;
			int i;
			for (i = 0; i < len_substr; i++)
			{
				if (*(str + len_str + i) != *(substr + i))
				{
					res = FALSE;
					break;
				}
			}
		}
		len_str++;
	}
	if (res)
	{
		return (len_str - 1);
	}
	else
	{
		return -1;
	}
}

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
char* str_replace(char* str, char* rep, char* origin)
{
	if (!str_compare(rep, origin))
	{
		int loc = 0;
		char* str_temp = (char*) (malloc(sizeof(char) * 100));
		*(str_temp) = '\0';
		char* p = str;
		int i = 0, j = 0;
		int str_temp_len;
		int origin_len = str_getlen(origin);
		int rep_len = str_getlen(rep);
		while (-1 != (loc = str_getlocation(p, origin)))
		{
			loc = str_getlocation(p, origin);
			str_temp_len = str_getlen(str_temp);
			for (i = 0; i < loc; i++)
			{
				*(str_temp + str_temp_len + i) = *(p + i);
			}
			for (j = 0; j < rep_len; j++)
			{
				*(str_temp + str_temp_len + i + j) = *(rep + j);
			}
			*(str_temp + str_temp_len + i + j + 1) = '\0';
			p = p + loc + origin_len;
		}
		//for (j = 0; j < 3; j++) {
		//	*(str + j) = *(str_temp + j);
		//	*(str + j + 1) = '\0';
		//}
		//*(str) = '\0';
		//strcpy(str, str_temp);
		//str[1] = 'F';
		printf("str_temp:%s\n", str_temp);
		printf("str:%s\n", str);
	}
	return str;
}

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
BOOL str_compare(char* str, char* substr)
{
	BOOL res = TRUE;
	if (str_getlen(str) != str_getlen(substr))
	{
		res = FALSE;
	}
	else
	{
		int i = 0;
		while ('\0' != *(str + i) && '\0' != *(substr + i))
		{
			if (*(str + i) != *(substr + i))
			{
				res = FALSE;
				break;
			}
		}
	}
	return res;
}

/**
 * 14. copy a string from buffer
 */
char* str_copy(char* str);

/**
 * 15. write the chars into buffer from string
 */
char* buff_write(char* str, char* origin)
{
	int i;
	for (i = 0; i < str_getlen(origin), i < SIZE_OF_BUFFER; i++)
	{
		*(str + 1) = *(origin + 1);
	}
	*(str + str_getlen(origin)) = '\0';
	return str;
}

