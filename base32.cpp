#include "base32.h"
#include "gazi.h"
#include "command.h"
#include "context.h"
#include "heap.h"
#include <stdio.h>

inline bool i::base32::isready(){
	const i::command* current_ = i::context::EIP;
	if(current_ != NULL  && current_->next != NULL){
		return true;
	}
	return false;
}


void i::base32::invoke(const char* function){

	if(strcmp(function , "mov")==0){
		if(isready()){

			if(i::context::EIP->totype == TYPE_VAR){
				if(i::context::EIP->fromtype==TYPE_VAR){
					i::base32::vartovar();
				}
				if(i::context::EIP->fromtype==TYPE_REG_EAX){
					i::base32::regtovar();
				}
				if(i::context::EIP->fromtype==TYPE_INST){
					i::base32::insttovar();
				}
			}

			if(i::context::EIP->totype==TYPE_REG_EAX ||
				i::context::EIP->totype==TYPE_REG_EBX || 
				i::context::EIP->totype==TYPE_REG_ECX || 
				i::context::EIP->totype==TYPE_REG_EDX){
					if(i::context::EIP->fromtype==TYPE_VAR){
						i::base32::vartoreg();
					}
					if(i::context::EIP->fromtype==TYPE_INST){
						i::base32::insttoreg();
					}
					if(i::context::EIP->fromtype==TYPE_REG_EAX ||
						i::context::EIP->fromtype==TYPE_REG_EBX || 
						i::context::EIP->fromtype==TYPE_REG_ECX || 
						i::context::EIP->fromtype==TYPE_REG_EDX){
							i::base32::regtoreg();
					}

			}
		}
	}

	if(strcmp(function , "add")==0){
		//TODO;


	}
}

inline void i::base32::vartovar(){
	const char* from_value =  i::context::mem->getvalue(i::context::scope, i::context::EIP->from);
	i::context::mem->setvalue(const_cast<char*>(i::context::scope),i::context::EIP->to,from_value);
}

void i::base32::regtovar(){
	char* value = NULL;
	if(context::EIP->fromtype  == i::TYPE_REG_EAX ){
		value = i::heap::mallocvalue(context::reg->find("EAX"));
	}
	if(context::EIP->fromtype  == i::TYPE_REG_EBX ){
		value = i::heap::mallocvalue(context::reg->find("EBX"));

	}
	if(context::EIP->fromtype  == i::TYPE_REG_ECX ){
		value = i::heap::mallocvalue(context::reg->find("ECX"));
	}
	if(context::EIP->fromtype  == i::TYPE_REG_EDX ){
		value = i::heap::mallocvalue(context::reg->find("EDX"));
	}
	context::mem->setvalue(context::scope,context::EIP->to,value);
}

inline void i::base32::insttovar(){
	const char* oldvalue = context::mem->getvalue(context::scope,context::EIP->to);
	if(oldvalue!=NULL) {
		if(strcmp(context::mem->getvalue(context::scope,context::EIP->to),context::EIP->from)==0) return ;
	}
	char* value = i::heap::mallocvalue(context::EIP->from);
	i::heap::freevalue(context::mem->getvalue(context::scope,context::EIP->to));
	context::mem->setvalue(context::scope,context::EIP->to,value);

}

void i::base32::insttoreg(){
	if(context::EIP->totype  == i::TYPE_REG_EAX ){
		if(context::reg->find("EAX") != NULL){
			if(strcmp(context::EIP->from,context::reg->find("EAX")) == 0) return;
		}
		char* oldvalue = context::reg->find("EAX");
		i::heap::freevalue(oldvalue);

		char* value = i::heap::mallocvalue(context::EIP->from);
		context::reg->insert("EAX",value);
	}
	if(context::EIP->totype  == i::TYPE_REG_EBX ){
		if(context::reg->find("EBX") != NULL){
			if(strcmp(context::EIP->from,context::reg->find("EBX")) == 0) return;
		}
		char* oldvalue = context::reg->find("EBX");
		i::heap::freevalue(oldvalue);

		char* value = i::heap::mallocvalue(context::EIP->from);
		context::reg->insert("EBX",value);
	}
	if(context::EIP->totype  == i::TYPE_REG_ECX ){
		if(context::reg->find("ECX") != NULL){
			if(strcmp(context::EIP->from,context::reg->find("ECX")) == 0) return;
		}
		char* oldvalue = context::reg->find("ECX");
		i::heap::freevalue(oldvalue);

		char* value = i::heap::mallocvalue(context::EIP->from);
		context::reg->insert("ECX",value);
	}
	if(context::EIP->totype  == i::TYPE_REG_EDX ){
		if(context::reg->find("EDX") != NULL){
			if(strcmp(context::EIP->from,context::reg->find("EDX")) == 0) return;
		}
		char* oldvalue = context::reg->find("EDX");
		i::heap::freevalue(oldvalue);

		char* value = i::heap::mallocvalue(context::EIP->from);
		context::reg->insert("EDX",value);
	}
}

void i::base32::vartoreg(){
	if(context::EIP->totype  == i::TYPE_REG_EBX ){
		const char* fromvalue = i::context::mem->getvalue(i::context::scope, i::context::EIP->from);
		if(context::reg->find("EAX") != NULL){
			if(strcmp(fromvalue,context::reg->find("EAX")) == 0) return;
		}
		char* oldvalue = context::reg->find("EAX");
		i::heap::freevalue(oldvalue);

		char* value = i::heap::mallocvalue(fromvalue);
		context::reg->insert("EAX",value);
	}
	if(context::EIP->totype  == i::TYPE_REG_EBX ){
		const char* fromvalue = i::context::mem->getvalue(i::context::scope, i::context::EIP->from);
		if(context::reg->find("EBX") != NULL){
			if(strcmp(fromvalue,context::reg->find("EBX")) == 0) return;
		}
		char* oldvalue = context::reg->find("EBX");
		i::heap::freevalue(oldvalue);

		char* value = i::heap::mallocvalue(fromvalue);
		context::reg->insert("EBX",value);
	}
	if(context::EIP->totype  == i::TYPE_REG_ECX ){
		const char* fromvalue = i::context::mem->getvalue(i::context::scope, i::context::EIP->from);
		if(context::reg->find("ECX") != NULL){
			if(strcmp(fromvalue,context::reg->find("ECX")) == 0) return;
		}
		char* oldvalue = context::reg->find("ECX");
		i::heap::freevalue(oldvalue);

		char* value = i::heap::mallocvalue(fromvalue);
		context::reg->insert("ECX",value);
	}
	if(context::EIP->totype  == i::TYPE_REG_EDX ){
		const char* fromvalue = i::context::mem->getvalue(i::context::scope, i::context::EIP->from);
		if(context::reg->find("EDX") != NULL){
			if(strcmp(fromvalue,context::reg->find("EDX")) == 0) return;
		}
		char* oldvalue = context::reg->find("EDX");
		i::heap::freevalue(oldvalue);

		char* value = i::heap::mallocvalue(fromvalue);
		context::reg->insert("EDX",value);
	}
}

void i::base32::regtoreg(){
	const char* from_value =  i::context::mem->getvalue(i::context::scope, i::context::EIP->from);
	i::context::mem->setvalue(const_cast<char*>(i::context::scope),i::context::EIP->to,from_value);
}

