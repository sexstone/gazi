#include "heap.h"
#include "gazi.h"
#include <string.h>
#include <stdio.h>


char* i::heap::mallocvalue(const char* str){
	if(str == NULL)  return NULL;
	int lengths = strlen(str);
	char* newstr = new char[lengths+1];
	char ch = *str;
	for(int i = 0 ; i <= lengths;++i){
		newstr[i] = ch;
		str++;
		ch = *str;
	}
	return newstr;
}

void  i::heap::freevalue(const char* str){
	
		delete str;
}