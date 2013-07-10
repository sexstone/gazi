#include "heap.h"
#include "gazi.h"
#include <string.h>


char* i::heap::mallocvalue(const char* str){
	if(str == NULL)  return NULL;
	int lengths = strlen(str)+1;
	char* newstr = new char[lengths];
	char ch = *str;
	for(int i = 0 ; i < lengths;++i){
		newstr[i] = ch;
		str++;
		ch = *str;
	}
	newstr[lengths]='\0';
	return newstr;
}

void  i::heap::freevalue(const char* str){
		delete[] str;
}