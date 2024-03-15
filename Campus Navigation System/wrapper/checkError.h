#pragma once
#ifdef DEBUG
	#define glCall(function) function;checkError(); 
#else
	#define glCall(function) function;
#endif
void checkError();