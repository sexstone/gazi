#include "executer.h"
#include  "gazi.h"
#include  "context.h"
#include  "scanner.h"
#include <conio.h>
#include <stdio.h>



void gazi::executer::read(const char* str){
	gazi::inner::context::init();
	if(!(gazi::inner::context::isinitsuccess))  return ;

	gazi::inner::scanner s(str) ;
	s.scan();
}

void gazi::executer::execute(){
	int i_debug_  = 0 ;
#ifdef _DEBUG_
	printf("=============runtime info============\n" );
#endif
	while(i::context::EIP != NULL &&  i::context::EIP->next != NULL){	
		const char* cmdname = i::context::EIP->name;

		i::context::lib->refence->invoke(cmdname);

#ifdef _DEBUG_
		printf("CMD:[%d]\n" , i_debug_); 
		printf("  EAX:%s" , i::context::reg->find(i::context::EAX)); 
		printf("  EBX:%s" , i::context::reg->find(i::context::EBX)); 
		printf("  ECX:%s" , i::context::reg->find(i::context::ECX));
		if(i::context::EIP->totype == i::TYPE_VAR){
			printf("  EDX:%s" , i::context::reg->find(i::context::EDX));
			printf("  %s:%s\n",i::context::EIP->to,i::context::mem->getvalue(i::context::scope, i::context::EIP->to));
		}else{
			printf("  EDX:%s\n" , i::context::reg->find(i::context::EDX));
		}

		i_debug_++;
#endif
		const i::command* t_ = i::context::EIP->next;
		i::context::EIP = t_;
	}
	printf("%s\n","");
	printf("%s\n","按任意键退出!");
	_getch();
}