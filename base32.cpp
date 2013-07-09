#include "base32.h"
#include "gazi.h"
#include "command.h"
#include "context.h"
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
			const char* to_  =  i::context::EIP->to;
			const char* from_ =  i::context::EIP->from;
			
			switch(i::context::EIP->totype){
					case TYPE_VAR:{
						if(i::context::EIP->fromtype==TYPE_VAR){
							i::base32::vartovar();
						}
						if(i::context::EIP->fromtype==TYPE_REG_EAX){
							i::base32::regtovar();
						}
						if(i::context::EIP->fromtype==TYPE_INST){
							i::base32::insttovar();
						}
							

						break;
								  }
					case TYPE_REG_EAX:{
						break;
									  }
					case TYPE_REG_EBX:{
						break;
									  }
					case TYPE_REG_ECX:{
						break;
									  }
					case TYPE_REG_EDX:{
						break;
									  }
					default:{
						break;
							}

			}
		}

	}

	if(strcmp(function , "add")==0){
		//TODO;


	}

}


inline void i::base32::vartovar(){
	const char*  from_key_ = context::EIP->from;
	const char*  from_value_ = context::mem->getvalue(i::context::scope, from_key_) ;
	const char*  to_key_  =  context::EIP->to;
	context::mem->setvalue(context::scope,to_key_,from_value_);

}

inline void i::base32::regtovar(){
	const char*  from_key_ = context::EIP->from;
	const char*  from_value_ = NULL;
	if(context::EIP->fromtype  == i::TYPE_REG_EAX ){
		from_value_ = context::reg->find(i::context::EAX);
	}
	if(context::EIP->fromtype  == i::TYPE_REG_EBX ){
		from_value_ = context::reg->find(i::context::EBX);
	}
	if(context::EIP->fromtype  == i::TYPE_REG_ECX ){
		from_value_ = context::reg->find(i::context::ECX);
	}
	if(context::EIP->fromtype  == i::TYPE_REG_EDX ){
		from_value_ = context::reg->find(i::context::EDX);
	}
	const char*  to_key_  =  context::EIP->to;
	context::mem->setvalue(context::scope,to_key_,from_value_);
}

inline void i::base32::insttovar(){
	const char*  from_value_ = context::EIP->from;
	const char*  to_key_  =  context::EIP->to;
	context::mem->setvalue(context::scope,to_key_,from_value_);
}




