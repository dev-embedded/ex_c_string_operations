#include <stdio.h>
#include <stdlib.h>
#include "string_ops.h"

int main()
{
	char* str = "abcedefasidefdfz";
	char* substr = "def";
	int len_str = str_getlen(str);
	printf("str_getlen() : %d\n",len_str);
	printf("str_getlocation(def) : %d\n",str_getlocation(str,substr));
	printf("hello , world !\n");
	return 0;
}


