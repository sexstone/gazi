#include "command.h"
#include "context.h"
namespace gazi { namespace inner {
	class scanner {
	public :
		scanner(const char* cmdstring):
		   cmdstring_(cmdstring),
			   maxposition(strlen(cmdstring)),
			   currentposition(0),
			   endscancmd(false),
			   endscantovalue(false),
			   endscanfromvalue(false),
			   fantalerror(false){};

		   void scan ();

		   inline void scannextcmd(){
			   if(scancmdcomplete()){
				   command* nextcmd =  new command;
				   nextcmd->init();
				   nextcmd->pre  =context::cmd ;
				   context::cmd->next =nextcmd ;
				   context::cmd = nextcmd;

				   endscancmd =false;
				   endscantovalue=false;
				   endscanfromvalue=false;
			   }
		   }

		   inline void nextposition(){
			   currentposition =1+currentposition;
		   }


		   inline void setendscancmd(bool isendscancmd){
			   endscancmd = isendscancmd;
		   }

		   inline bool getendscancmd(){
			   return endscancmd;
		   }

		   inline bool getendscantovalue(){
			   return endscantovalue;
		   }

		   inline void setendscantovalue(bool to){
			   endscantovalue = to;
		   }

		   inline bool getendscanfromvalue(){
			   return endscanfromvalue;
		   }

		   inline void setendscanfromvalue(bool from){
			   endscanfromvalue = from;
		   }



	private :
		inline  bool scancmdcomplete(){
			if(endscancmd  && endscantovalue && endscanfromvalue){
				return true;
			}
			return false;
		}
		void scanregeist( );
		void scanmov();
		void scaninst();
		void scanvar();

		const char* cmdstring_ ;
		int  maxposition;
		int  currentposition;
		bool  endscancmd;
		bool  endscantovalue;
		bool  endscanfromvalue;

		bool fantalerror;


	};
}}