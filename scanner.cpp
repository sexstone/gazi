#include "scanner.h"
#include "command.h"
#include "gazi.h"
#include <string.h>
#include <stdio.h>



void i::scanner::scan(){

	if(cmdstring_ != NULL){
		while(currentposition < maxposition && !fantalerror){
			char key  = *cmdstring_;
			if(key != '\0'){
				switch(key){
					//MOV CMD
					case 'm':{
						scanmov();
						break;
							 }

					case 'E' :{
						scanregeist();
						scannextcmd();
						break;
							  }
					//var @name
					case '@' :{
						scanvar();
						scannextcmd();
						break;
							  }
					//[...]
					case '[' :{
						scaninst();
						scannextcmd();
						break;
							  }

					default:{
						cmdstring_++;
						nextposition();
						scannextcmd();
						break;
							}
				}
			}
		}
	}
	LOG("GaZi","scanning is completed.");
#ifdef _DEBUG_
	int i_debug_ = 0;
	const command* temp = i::context::EIP ;
	LOG("","******************************");
	LOG("","***      formating code    ***");
	LOG("","******************************"); 
	while(context::EIP != NULL &&  i::context::EIP->next != NULL){
		
		printf("CMD:[%d]\n" , i_debug_); 
		printf("  %s" , i::context::EIP->name); 
		printf("  %s" , i::context::EIP->to); 
		printf("  %s\n" , i::context::EIP->from); 
		i_debug_++;
		context::EIP = i::context::EIP->next;
	}
	i::context::EIP = temp;
#endif
}


void i::scanner::scanregeist(){
	//EAX regiest
	if(!getendscantovalue()){
		if(i::context::cmd->to == NULL){
			i::context::cmd->to = "E" ;
		}
		cmdstring_++;
		nextposition();

		char t = *cmdstring_ ;
		cmdstring_--;
		if(t == 'A') {
			if(strcmp( i::context::cmd->to ,"E")==0 ){
				char temp =  *cmdstring_;
				if( temp == 'E'  ){
					i::context::cmd->to = "EA";
				}
			}
		}
		if(t == 'B') {
			if(strcmp( i::context::cmd->to ,"E")==0 ){
				char temp =  *cmdstring_;
				if( temp == 'E'  ){
					i::context::cmd->to = "EB";
				}
			}
		}
		if(t == 'C') {
			if(strcmp( i::context::cmd->to ,"E")==0 ){
				char temp =  *cmdstring_;
				if( temp == 'E'  ){
					i::context::cmd->to = "EC";
				}
			}
		}
		if(t == 'D') {
			if(strcmp( i::context::cmd->to ,"E")==0 ){
				char temp =  *cmdstring_;
				if( temp == 'E'  ){
					i::context::cmd->to = "ED";
				}
			}
		}
		cmdstring_=cmdstring_+2;
		nextposition();	
		//EAX STEP 1
		t = *cmdstring_ ;
		cmdstring_--;
		if(t == 'X') {
			if(strcmp(i::context::cmd->to ,"EA")==0){
				char temp =  *cmdstring_;
				if( temp == 'A' ){
					i::context::cmd->to = "EAX";
				}
			}
			if(strcmp(i::context::cmd->to ,"EB")==0){
				char temp =  *cmdstring_;
				if( temp == 'B' ){
					i::context::cmd->to = "EBX";
				}
			}
			if(strcmp(i::context::cmd->to ,"EC")==0){
				char temp =  *cmdstring_;
				if( temp == 'C' ){
					i::context::cmd->to = "ECX";
				}
			}
			if(strcmp(i::context::cmd->to ,"ED")==0){
				char temp =  *cmdstring_;
				if( temp == 'D' ){
					i::context::cmd->to = "EDX";
				}
			}
		}
		cmdstring_=cmdstring_+2;
		nextposition();	
		//EAX STEP 2
		t = *cmdstring_ ;
		cmdstring_--;
		if(t == ' ') {
			if(strcmp(i::context::cmd->to ,"EAX")==0){
				i::context::cmd->totype = i::TYPE_REG_EAX;
				setendscantovalue(true);
			}
			if(strcmp(i::context::cmd->to ,"EBX")==0){
				i::context::cmd->totype = i::TYPE_REG_EBX;
				setendscantovalue(true);
			}
			if(strcmp(i::context::cmd->to ,"ECX")==0){
				i::context::cmd->totype = i::TYPE_REG_ECX;

				setendscantovalue(true);
			}
			if(strcmp(i::context::cmd->to ,"EDX")==0){
				i::context::cmd->totype = i::TYPE_REG_EDX;
				setendscantovalue(true);
			}
		}
		cmdstring_=cmdstring_+2;
		nextposition();
	}else{

		if(!getendscanfromvalue()){
			if(i::context::cmd->from == NULL){
				i::context::cmd->from = "E" ;
			}
			cmdstring_++;
			nextposition();

			char t = *cmdstring_ ;
			cmdstring_--;
			if(t == 'A') {
				if(strcmp( i::context::cmd->from ,"E")==0 ){
					char temp =  *cmdstring_;
					if( temp == 'E'  ){
						i::context::cmd->from = "EA";
					}
				}
			}
			if(t == 'B') {
				if(strcmp( i::context::cmd->from ,"E")==0 ){
					char temp =  *cmdstring_;
					if( temp == 'E'  ){
						i::context::cmd->from = "EB";
					}
				}
			}
			if(t == 'C') {
				if(strcmp( i::context::cmd->from ,"E")==0 ){
					char temp =  *cmdstring_;
					if( temp == 'E'  ){
						i::context::cmd->from = "EC";
					}
				}
			}
			if(t == 'D') {
				if(strcmp( i::context::cmd->from ,"E")==0 ){
					char temp =  *cmdstring_;
					if( temp == 'E'  ){
						i::context::cmd->from = "ED";
					}
				}
			}
			cmdstring_=cmdstring_+2;
			nextposition();	
			//EAX STEP 1
			t = *cmdstring_ ;
			cmdstring_--;
			if(t == 'X') {
				if(strcmp(i::context::cmd->from ,"EA")==0){
					char temp =  *cmdstring_;
					if( temp == 'A' ){
						i::context::cmd->from = "EAX";
					}
				}
				if(strcmp(i::context::cmd->from ,"EB")==0){
					char temp =  *cmdstring_;
					if( temp == 'B' ){
						i::context::cmd->from = "EBX";
					}
				}
				if(strcmp(i::context::cmd->from ,"EC")==0){
					char temp =  *cmdstring_;
					if( temp == 'C' ){
						i::context::cmd->from = "ECX";
					}
				}
				if(strcmp(i::context::cmd->from ,"ED")==0){
					char temp =  *cmdstring_;
					if( temp == 'D' ){
						i::context::cmd->from = "EDX";
					}
				}
			}
			cmdstring_=cmdstring_+2;
			nextposition();	
			//EAX STEP 2
			t = *cmdstring_ ;
			cmdstring_--;
			if(t == ' ') {
				if(strcmp(i::context::cmd->from ,"EAX")==0){
					i::context::cmd->fromtype = i::TYPE_REG_EAX;
					setendscanfromvalue(true);
				}
				if(strcmp(i::context::cmd->from ,"EBX")==0){
					i::context::cmd->fromtype = i::TYPE_REG_EBX;
					setendscanfromvalue(true);
				}
				if(strcmp(i::context::cmd->from ,"ECX")==0){
					i::context::cmd->fromtype = i::TYPE_REG_ECX;
					setendscanfromvalue(true);
				}
				if(strcmp(i::context::cmd->from ,"EDX")==0){
					i::context::cmd->fromtype = i::TYPE_REG_EDX;
					setendscanfromvalue(true);
				}
			}
			cmdstring_=cmdstring_+2;
			nextposition();
		}
	}
}


void i::scanner::scaninst(){
	if(!getendscantovalue()){
		char varname [MAX_INST_LENGTH];
		cmdstring_++;
		nextposition();
		char ch = *cmdstring_ ;
		int nums = 0;
		while((ch != ']') && (nums<MAX_VARNAME_LENGTH-1) ){
			varname[nums] = ch;
			nums++;
			cmdstring_++;
			nextposition();
			ch = *cmdstring_ ;
		}
		if(ch ==']'){
			cmdstring_++;
			nextposition();
			varname[nums] = '\0';
			char* varname_ = new char[nums];
			strcpy(varname_ ,  varname);
			i::context::cmd->to = varname_;
			i::context::cmd->totype = i::TYPE_INST;
			setendscantovalue(true);
		}
		
	}else{

		if(!getendscanfromvalue()){
			char varname [MAX_INST_LENGTH];
			cmdstring_++;
			nextposition();
			char ch = *cmdstring_ ;
			int nums = 0;
			while((ch != ']') && (nums<MAX_VARNAME_LENGTH-1) ){
				varname[nums] = ch;
				nums++;
				cmdstring_++;
				nextposition();
				ch = *cmdstring_ ;
			}
			if(ch ==']'){
				cmdstring_++;
				nextposition();
				varname[nums] = '\0';
				char* varname_ = new char[nums];
				strcpy(varname_ ,  varname);
				i::context::cmd->from = varname_;
				i::context::cmd->fromtype = i::TYPE_INST;
				setendscanfromvalue(true);
			}
		}
	}
}

void i::scanner::scanvar(){
	if(!getendscantovalue()){
		char varname [MAX_VARNAME_LENGTH];
		cmdstring_++;
		nextposition();
		char ch = *cmdstring_ ;
		int nums = 0;
		varname[nums] = '@';
		while((ch != ' ') && (nums<MAX_VARNAME_LENGTH-2) ){
			varname[++nums] = ch;
			cmdstring_++;
			nextposition();
			ch = *cmdstring_ ;
		}
		varname[++nums] = '\0';
		char* varname_ = new char[nums];
		strcpy(varname_ ,  varname);
		i::context::cmd->to = varname_;
		i::context::cmd->totype = i::TYPE_VAR;
		setendscantovalue(true);
	}else{

		if(!getendscanfromvalue()){
			char varname [MAX_VARNAME_LENGTH];
			cmdstring_++;
			nextposition();
			char ch = *cmdstring_ ;
			int nums = 0;
			varname[nums] = '@';
			while((ch != ' ') && (nums<MAX_VARNAME_LENGTH-2) ){
				varname[++nums] = ch;
				cmdstring_++;
				nextposition();
				ch = *cmdstring_ ;
			}
			varname[++nums] = '\0';
			char* varname_ = new char[nums];
			strcpy(varname_ ,  varname);
			i::context::cmd->from = varname_;
			i::context::cmd->fromtype = i::TYPE_VAR;
			setendscanfromvalue(true);
		}
	}

}

void i::scanner::scanmov(){
	//STEP 1
	if(!getendscancmd()){
		if(i::context::cmd->name == NULL){
			i::context::cmd->name = "m";
		}
		cmdstring_++;
		nextposition();
		//STEP 2
		char t = *cmdstring_ ;
		cmdstring_--;
		if(t == 'o') {
			if(strcmp(i::context::cmd->name ,"m")==0 ){
				char temp =  *cmdstring_;
				if( temp == 'm' ){
					i::context::cmd->name = "mo";
				}
			}
		}
		cmdstring_=cmdstring_+2;
		nextposition();	
		//STEP 3
		t = *cmdstring_ ;
		cmdstring_--;
		if(t == 'v') {
			if(strcmp(i::context::cmd->name,"mo")==0){
				char temp =  *cmdstring_;
				if( temp == 'o'  ){
					i::context::cmd->name = "mov";
				}
			}
		}
		cmdstring_=cmdstring_+2;
		nextposition();	
		//STEP 4
		t = *cmdstring_ ;
		cmdstring_--;
		if(t == ' '){
			char temp =  *cmdstring_;
			if( (temp == 'v')  && strcmp(i::context::cmd->name,"mov") ==0 ){
				setendscancmd(true);
			}
		}
		cmdstring_ =cmdstring_+2;
		nextposition();
	}

}


//TODO  cmd   loop   push  pop  call  ret (add  write  open  close)
