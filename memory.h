#ifndef _memory_h_
#define _memory_h_

#include "map.h"
#include <string>

namespace gazi {
	namespace inner{
		class  memory{

		public:
			memory(){};
			~memory(){};

			void init();
			void addscope(const char* scope);
			const char* getvalue(const char* scope,const char* key);
			void setvalue(const char* scope,const char* key ,const char*value);
			void erasescope(const char* scope);
			void destroy();
			//friend const char[] String(const char*);

		private:
			gazi::inner::map<char*,map<char*,char*>*>* map_;
			void operator=(const memory&);
			gazi::inner::memory(const memory&);
		};
	}
}
#endif