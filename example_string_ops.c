#include <stdio.h>
#include <stdlib.h>
#include "string_ops.h"

int main()
{
	char* str = buff_create();
	str = "abcedefadef";
	char* substr = "def";
	char* rep = "zaqz";
	printf("str:%s\n", str);
	printf("substr:%s\n", substr);
	printf("rep:%s\n", rep);
	printf("=====test of operation of the string======\n");
	printf("4.str_getlen() : %d\n", str_getlen(str));
	printf("--------------------\n");
	printf("5.buff_isfull() : ");
		BOOL res_full = buff_isfull(str);
		if (TRUE == res_full)
		{
			printf("str is full\n");
		}else{
			printf("str is not full\n");
		}
		printf("--------------------\n");
	printf("6.buff_isempty() : ");
	BOOL res_empty = buff_isempty(str);
	if (TRUE == res_empty)
	{
		printf("str is empty\n");
	}else{
		printf("str is not empty\n");
	}
	printf("--------------------\n");
	printf("7.str_getlocation('def') : %d\n", str_getlocation(str, substr));
	printf("--------------------\n");
	//printf("8.str_insert(str,'def',3) : %s\n", str_insert(str, substr, 3));
	//printf("--------------------\n");
	printf("10.str_replace(str, rep, substr) : ");
	str_replace(str, rep, substr);
	printf("--------------------\n");
	return 0;
}

