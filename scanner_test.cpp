#include "scanner.h"
#include "map.h"
#include "context.h"
#include "gazi.h"
#include "heap.h"
#include "base32.h"
#include  "executer.h"
#include <stdio.h>
#include  <string.h>
#include  <iostream>




void Testscanner(){
	const char* str  = "mov @var1 [i love you!]  mov @var2 @var1  mov EAX @var1   mov EBX EAX   mov EDX [qiyahong]   mov EAX EDX ";  
	gazi::executer e;
	e.read(str);
	e.execute();
};



int main(){
	   
	Testscanner();

}

