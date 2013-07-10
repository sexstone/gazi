#ifndef _myia32_h_
#define _myia32_h_

#ifndef _DEBUG_
#define _DEBUG_
#endif

#ifndef _LOG_
#define _LOG_
#endif
#ifdef _LOG_
#define LOG(VAR,DESCRIBE)  printf("%s : %s\n",VAR,DESCRIBE)
#endif

#define MAX_VARNAME_LENGTH 100
#define MAX_VARVALUE_LENGTH 100
#define MAX_INST_LENGTH 100
#define ENTER_INNER

namespace gazi{namespace inner {
	static const char* TOP_SCOPE = "0" ;

}}

namespace i = gazi::inner;

#endif
