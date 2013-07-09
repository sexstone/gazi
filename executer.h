#ifndef _executer_h_
#define _executer_h


#include "gazi.h"
#include "context.h"
#include <stdio.h>


namespace gazi {
	class executer{
	public:
		executer(){}
		~executer(){}

		void read(const char*);
		void execute();
	private:
		void operator=(const executer&);
		executer (const executer&);

	};
}

#endif