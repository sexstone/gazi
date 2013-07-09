#ifndef _gazi_internal_base32_h_
#define _gazi_internal_base32_h_

#include "gazi.h"

namespace gazi {
	namespace inner{
		class plugin{
		public:
			virtual const char* pluginname() = 0;
			virtual void init() = 0;
			virtual void invoke(const char*) = 0;
		};

		class base32:public plugin{
		public:
			base32(){}
			~base32(){}

			const char* pluginname() {
				return "base32";
			}

			void init(){}
			void invoke(const char*);

		private:
			inline bool isready();
		
			inline void regtovar();
			inline void vartovar();
			inline void insttovar();

			void operator=(const gazi::inner::base32 &) ;
			gazi::inner::base32(const gazi::inner::base32 &);
		};


	}
}

#endif