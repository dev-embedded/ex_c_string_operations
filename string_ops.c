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
void buff_free(char *buff)
{
	if (buff != NULL)
		free(buff);
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
 * 5. Return the status of buffer (full). If the last char of buff is '\0',
 *    and the other chars are not '\0', we define the buff as full.
 * Specially, I think '\0' should be included in the buff length; so,
 *    if '\0' in missing the string, return err -1.
 * Note: '\0' is not included in the length of a string, but it is included in buff length.
 */
BOOL buff_isfull(char* str)
{
	int i;
	for (i = 0; i < STR_SIZE - 1; i++)
		if (str[i] == '\0')
			return (FALSE);
	if (str[i] == '\0')
		return (TRUE);
	else
		return (-1);
}

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
 * 8. Insert a sub-string in a string from the place of index; if the final length
 *    of the string is longer than STR_SIZE, the excess part will be discarded.
 */
char* str_insert(char* str, char* substr, int index)
{
	int len = str_getlen(str);
	if (index > len)
		return (str);   //the index is outside the string
	int slen = str_getlen(substr);
	int i;
	if ((len + slen) <= STR_SIZE)   //enough space for str + substr
	{
		for (i = index; i < len; i++)
			str[len + slen - i] = str[len - i]; //move str behind index part back
		for (i = 0; i < slen; i++)
			str[index + i] = substr[i];  //insert substr
	}
	else if ((index + slen) >= STR_SIZE) //even part of substr should be discarded.
	{
		for (i = 0; i < STR_SIZE - index; i++)  //can only insert part of substr
			str[index + i] = substr[i];
	}
	else			// substr can be insert, but part of str will be discarded.
	{
		for (i = index; i < STR_SIZE - len; i++)
			str[STR_SIZE - i] = str[STR_SIZE - len - i]; //move part of str back for substr
		for (i = 0; i < slen; i++)
			str[index + i] = substr[i];  //insert substr
	}
	return (str);
}

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
		free(str_temp);
	}
	return str;
}

/**
 * 11. Sort of string(from small to big with ASCII code).
 */
char* str_sort(char* str)
{
	int i, j;
	char c;
	int len = str_getlen(str);
	for (i = 0; i < len; i++)
		for (j = i + 1; j < len; j++)
			if (str[i] > str[j])
			{
				c = str[i];
				str[i] = str[j];
				str[j] = c;
			}
	return (str);
}

/**
 * 12. Return the times of a substring repeat in a string, return 0 if substr doesnot
 *     appear in str.
 *     Specially, if str = "abbbc", and substr = "bb", then return is 2.
 */
int str_rep(char* str, char* substr)
{
	int c = 0;  // for count the times
	int loc = str_getlocation(str, substr);
	while (loc != -1)
	{
		c++;
		char* temp = str + loc + 1;
		loc = str_getlocation(temp, substr);
	}
	return (c);
}

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
/**
 * a. To compare two strings, if str1 == str2, return 0;
 *    if str1 != str2, return (str1-str2).
 */
int str_cmp(char* str1, char* str2)
{
	int i;
	for (i = 0; i < STR_SIZE; i++)
	{
		if (str1[i] == '\0')
			return (str1[i] - str2[i]);
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (str1[i] - str2[i]);
}

/**
 * b. To add two strings, str2 will be add to the end of str1, then return str1.
 *    The excess part outside STR_SIZE will be discarded.
 */
char* str_cat(char* str1, const char* str2)
{
	int len1 = str_getlen(str1);
	int len2 = str_getlen(str2);
	int i;
	if (len1 + len2 <= STR_SIZE)
	{
		for (i = 0; i < len2; i++)
			str1[len1 + i] = str2[i];
	}
	else
	{
		for (i = len1; i < STR_SIZE; i++)
			;
		str1[i] = str2[i - len1];
	}
	str1[i] = '\0';
	return (str1);
}

