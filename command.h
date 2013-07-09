#ifndef _command_h_
#define _command_h_

#include "gazi.h"
#include "base32.h"
#include <stdio.h>
namespace gazi { namespace inner {

	enum CMD_TYPE {
			NULL_TYPE,
			TYPE_VAR,
			TYPE_INST,
			TYPE_REG_EAX,
			TYPE_REG_EBX,
			TYPE_REG_ECX,
			TYPE_REG_EDX
	};

	struct command{
		const char* name ;
		const command* pre;
		const command* next;

		const char* from;
		i::CMD_TYPE  fromtype;

		const char* to;
		i::CMD_TYPE  totype;

		void init(){
			from = NULL;
			fromtype= NULL_TYPE;
			name =NULL;
			next =NULL;
			pre = NULL;
			to = NULL;
			totype=NULL_TYPE;
		}

	};

	struct library{
		const char* libraryname ;
		i::plugin* refence;
		library* next;

		void init(){
			libraryname = NULL;
			refence =NULL;
			next =NULL;
		}
	};
}}

#endif


