#include "memory.h"
#include "map.h"
#include "gazi.h"
#include <stdio.h>


void gazi::inner::memory::init(void){
	map_ =  new map<char*,map<char*,char*>*>();
	map<char*,char*>* scope0_ =  new map<char*,char*>();
	map_->insert(const_cast<char*>(i::TOP_SCOPE),scope0_);
}

void gazi::inner::memory::addscope(const char* scope){
	map<char*,char*>* scopex_ =  new map<char*,char*>();
	map_->insert(const_cast<char*>(scope),scopex_);
}

void gazi::inner::memory::erasescope(const char* scope){
	map_->erase(const_cast<char*>(scope));
}

const char* gazi::inner::memory::getvalue(const char* scope, const char* key){
	gazi::inner::map<char*,char*>* result  = reinterpret_cast<gazi::inner::map<char*,char*>*>(map_->find(const_cast<char*>(scope)));
	if(result != NULL){
		const char* value = result->find(const_cast<char*>(key));
		if(value != NULL){
			return value;
		}
	}
	return NULL;
}


void gazi::inner::memory::setvalue(const char* scope,const char* key ,const char*value){
	gazi::inner::map<char*,char*>* result  = reinterpret_cast<gazi::inner::map<char*,char*>*>(map_->find(const_cast<char*>(scope)));
	if(result != NULL){
		result->insert(const_cast<char*>(key),const_cast<char*>(value));
	}
}

