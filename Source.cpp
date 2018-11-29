#include <iostream>
using namespace std;
#include <string>
#include "Header.h"
MYSTRING::MYSTRING()
{
	size = 0;
	str = new char[size+1];
	str = NULL;
}
MYSTRING::MYSTRING(const MYSTRING &s)
{
	size = s.size;
	str = new char[size + 1];
	strcpy(str, s.str);
}
MYSTRING::MYSTRING(const char *&s)
{
	size = strlen(s);
	str = new char[size + 1];
	strcpy(str, s);
	str[size] = '\0';
}
MYSTRING::MYSTRING(int len)
{
	this->size = len;
	str = new char[len];
}
MYSTRING::MYSTRING()
{
	delete [] str;
}
MYSTRING& MYSTRING::operator=(const MYSTRING &s)
{ 
	delete[]str;
	size = strlen(s.str);
	str = new char[size + 1];
	strcpy(str, s.str);
	str[size] = '\0';
}
