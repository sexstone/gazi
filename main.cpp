#include  <iostream>

/**************************************************
//  this is gazi's script formation ,  something like x86 assembly language  and c language

.main(){
            mov @d [10000]
			if @a == @b
	        true:
				mov  @a  @b
				mov  EAX @a
				if  @c== @d
				true:			
					mov @c [2]
					mov @d [3]
				    jump if
			:true
	        false:
				call add(@var1 ,@var2, EAX,EBX);
				mov @a EAX
				mov @b EBX
			:false
	         mov @a @b
}
	
	
.add(@var1 ,@var2, EAX,EBX){
	......
}

****************************************************/