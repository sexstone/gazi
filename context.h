#ifndef _context_h_
#define _context_h_

#include "command.h"
#include "memory.h"
#include "map.h"
#include "gazi.h"
#include  <stdio.h>

namespace gazi { namespace inner {
class context{

public:
	enum REGISTER{
		EAX,
		EBX,
		ECX,
		EDX
	};
	
	static  gazi::inner::command* cmd;
	static  const gazi::inner::command* EIP;
	static  gazi::inner::map<REGISTER ,char*>* reg;  
	static  gazi::inner::memory* mem;
	static  gazi::inner::library* lib;
	static  int scope;
	 
	static bool isinitsuccess;

	static void init();
	static void addplugin(i::plugin* );
	
	static  void nextscope();
	static  void prescope();
	
	
private:
	context();
	~context();
	
	void operator=(const gazi::inner::context & ctx);
	gazi::inner::context(const gazi::inner::context &);
	
};
}}
#endif
