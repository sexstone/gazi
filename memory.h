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
			void addscope(const int scope);
			const char* getvalue(const int scope,const char* key);
			void setvalue(const int scope,const char* key ,const char*value);
			void erasescope(const int scope);
			void destroy();
			//friend const char[] String(const char*);

		private:
			gazi::inner::map<int,map<char*,char*>*>* map_;
			void operator=(const memory&);
			gazi::inner::memory(const memory&);
		};
	}
}
#endif