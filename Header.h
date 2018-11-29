#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <iostream>
using namespace std;
class MYSTRING
{ 
private:
	int size;
	char *str;
public:
	MYSTRING();
	MYSTRING(const MYSTRING &s);
	MYSTRING(const char *&s);
	MYSTRING(int len);
	~MYSTRING();
	MYSTRING& operator=(const MYSTRING&s);
};
#endif
