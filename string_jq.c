#include <stdlib.h>
#include "string_ops.h"

/**
* 1. Create a buffer, size is #define SIZE_OF_BUFFER.
*/
char* buff_create()
{
return ((char *)malloc(SIZE_OF_BUFFER));
}

/**
* 2. Free a buffer.
*/
void buff_free(char *buff)
{
if(buff != NULL) free(buff);
}

/**
* 3. Init the 1st char of buff to '\0'.
*/
BOOL buff_clean(char *buff)
{
*buff='\0';
return TRUE;
}

/**
* 4. Return the size of a string, char* str is the original string, the length of a string
*    must be less then or equal STR_SIZE.
*/
int str_getlen(const char* str)
{
int i;
for(i=0;i<STR_SIZE;i++)
	if(str[i]=='\0') return (i);
return (i);
}

/**
* 5. Return the status of buffer (full). If the last char of buff is '\0',
*    and the other chars are not '\0', we define the buff as full.
* Specially, I think '\0' should be included in the buff length; so,
*    if '\0' in missing the string, return err -1.
* Note: '\0' is not included in the length of a string, but it is included in buff length.
*/
BOOL buff_isfull(const char* str)
{
int i;
for(i=0;i<STR_SIZE-1;i++)
	if(str[i]=='\0') return(FALSE);
if(str[i]=='\0') return(TRUE);
else return(-1);
}

/**
* 6. Return the status of buffer (empty); if the first char of buff is '\0',
*    we define the buff as empty.
*/
BOOL buff_isempty(const char* str)
{
if(*str=='\0') return(TRUE);
else return(FALSE);
}

/**
* 7. Return the first location of char or the first char of substring;
*    return -1 if we can not find the location.
*/
int str_getlocation(const char* str, const char* substr)
{
int r;   //for return
int c;   //for count
int m=0;   //for mark
int i= str_getlen(str);
int j= str_getlen(substr);
if(i<j) return(-1);
for(r=0;r<=(i-j);r++)
	{
	m=0;
	for(c=0;c<j;c++)
		if(str[r+c]!=substr[r+c])
		{
		   m=1; break;
		}
	if(m==0) return(r);
	}
return (-1);
}

/**
* 8. Insert a sub-string in a string from the place of index; if the final length
*    of the string is longer than STR_SIZE, the excess part will be discarded.
*/
char* str_insert(char* str, const char* substr, const int index)
{
int len=get_strlen(str);
if(index>len) return(str);   //the index is outside the string
int slen=get_strlen(substr);
int i;
if((len+slen)<=STR_SIZE)   //enough space for str + substr
	{
	for(i=index;i<len;i++)
		str[len+slen-i]=str[len-i];  //move str behind index part back
	for(i=0;i<slen;i++)
		str[index+i]=substr[i];  //insert substr
	}
else if((index+slen)>=STR_SIZE) //even part of substr should be discarded.
	{
	for(i=0;i<STR_SIZE-index;i++)   //can only insert part of substr
		str[index+i]=substr[i];
	}
else				// substr can be insert, but part of str will be discarded.
	{
	for(i=index;i<STR_SIZE-len;i++)
		str[STR_SIZE-i]=str[STR_SIZE-len-i]; //move part of str back for substr
	for(i=0;i<slen;i++)
		str[index+i]=substr[i];  //insert substr
	}
return (str);
}

/**
* 9. Delete all of the char or the substring from the string.
*/
char* str_del(char* str, const char* substr)
{
int loc=-1,i;
int len=get_strlen(str);
int slen=get_strlen(substr);
while((loc=get_strlocation(str,substr))>=0)
	{
	for(i=0;i<len-loc-slen;i++)
		str[loc+i]=str[loc+slen+i]; // to remove substr part from str
	str[loc+i]='\0';  //set the end of the new string
	}
return (str);
}

/**
* 10. Replace all of the char or the substring with another in the string;
*     str is the string we work on, rep contains the replacing info,
*     while origin is the info to be replaced.
* Note: the excess part of STR_SIZE will be discarded.
*/
char* str_replace(char* str, const char* rep, const char* origin)
{
int loc = str_getlocation(str, origin);
int len=str_getlen(str);
int rlen=str_getlen(rep);
int olen=str_getlen(origin);
int i;
while (loc!=-1)
	{
	for(i=0;i<len-loc-olen;i++)  // to remove origin part from str
		str[loc+i]=str[loc+olen+i];
	str[loc+i]='\0';  //set the end of the new string
	str=str_insert(str, rep);  //then, insert rep part to str
	}
return (str);
}

/**
* 11. Sort of string(from small to big with ASCII code).
*/
char* str_sort(char* str)
{
int i,j;
char c;
int len=get_strlen(str);
for(i=0;i<len;i++)
	for(j=i+1;j<len;j++)
		if(str[i]>str[j])
		{
			c=str[i];str[i]=str[j];str[j]=c;
		}
return (str);
}

/**
* 12. Return the times of a substring repeat in a string, return 0 if substr doesnot
*     appear in str.
*     Specially, if str = "abbbc", and substr = "bb", then return is 2.
*/
int str_rep(const char* str, const char* substr)
{
int c=0;  // for count the times
int loc=get_location(str,substr);
while(loc!=-1)
	{
	c++;
	char* temp=str+loc+1;
	loc=geyt_location(temp,substr);
	}
return (c);
}

/**
 * a. To compare two strings, if str1 == str2, return 0;
 *    if str1 != str2, return (str1-str2).
 */
int str_cmp(const char* str1, const char* str2)
{
int i;
for(i=0;i<STR_SIZE;i++)
	{
	if(str1[i]=='\0') return(str1[i]-str2[i]);
	if(str1[i]!=str2[i]) return(str1[i]-str2[i]);
	}
return (str1[i]-str2[i]);
}

/**
 * b. To add two strings, str2 will be add to the end of str1, then return str1.
 *    The excess part outside STR_SIZE will be discarded.
 */
char* str_cat(char* str1, const char* str2)
{
int len1=str_getlen(str1);
int len2=str_getlen(str2);
int i;
if(len1+len2<=STR_SIZE)
	{
	for(i=0;i<len2;i++)
		str1[len1+i]=str2[i];
	}
else
	{
	for(i=len1;i<STR_SIZE;i++);
		str1[i]=str2[i-len1];
	}
str1[i]='\0';
return (str1);
}
