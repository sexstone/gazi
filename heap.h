#ifndef _gazi_internal_mallocvalue_h_
#define _gazi_internal_mallocvalue_h_

namespace gazi {
	namespace inner{
		class heap{
		public:
			static char* mallocvalue(const char*);
			static void freevalue(const char*);

		private:
			heap();
			~heap();
		};
}}

#endif