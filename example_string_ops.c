#include <stdio.h>
#include <stdlib.h>
#include "string_ops.h"

int main()
{
	char* str = buff_create();
	str = "abcedefa";
	printf("str:%s\n",str);
	char* substr = "def";
	char* rep = "zaqz";
	int len_str = str_getlen(str);
	printf("=====test of operation of the string======\n");
	printf("4.str_getlen() : %d\n",len_str);
	printf("--------------------\n");
	printf("7.str_getlocation(def) : %d\n",str_getlocation(str,substr));
	printf("--------------------\n");
	printf("10.str_replace(str, rep, substr) : %s\n",str_replace(str, rep, substr));
	printf("--------------------\n");
	return 0;
}


