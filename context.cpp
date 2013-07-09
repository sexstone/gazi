#include "context.h"
#include "command.h"
#include "base32.h"
#include "memory.h"
#include "gazi.h"
#include "map.h"


#include <stdio.h>


ENTER_INNER	
i::command* i::context::cmd = NULL;
const i::command* i::context::EIP = NULL;
int i::context::scope  = i::TOP_SCOPE;
i::memory* i::context::mem  = NULL;
i::library* i::context::lib = NULL;
i::map<i::context::REGISTER ,char*>* i::context::reg = NULL;
bool i::context::isinitsuccess = false;


void i::context::init(){
	cmd = new command;
	cmd->init();

	mem  = new memory();
	mem->init();

	lib =  new library();
	lib->init();
	i::plugin* b32_ = new i::base32();
	addplugin(b32_);

	EIP = cmd;

	reg = new map<context::REGISTER,char*>();
	reg->insert(EAX,"");
	reg->insert(EBX,"");
	reg->insert(ECX,"");
	reg->insert(EDX,"");

	isinitsuccess = true;

	LOG("Context","初始化成功");
}

void i::context::addplugin(i::plugin* p){
	gazi::inner::library* iter = lib;

loop:
	if(iter->libraryname == NULL) {
		char* name = const_cast<char*>(p->pluginname());
		iter->libraryname = name;
		iter->refence = p;

		library* lib_temp =  new library();
		lib_temp->init();
		iter->next = lib_temp;

		LOG(name, "基础库安装完成");
		
	}else{
		if(iter->next != NULL){
			iter = iter->next;
			goto loop;
		}
	}

	
	

	
}

void i::context::nextscope(){
	scope ++;
}

void i::context::prescope(){
	if(scope == 1)  return ;
	scope--;
}

