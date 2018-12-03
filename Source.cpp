#include <iostream>
using namespace std;
#include <string>
#include "Header.h"
MYSTRING::MYSTRING()
{
	len = 0;
	str = new char[len+1];
	str = NULL;
}
MYSTRING::MYSTRING(const MYSTRING &s)
{
	len = s.len;
	str = new char[len];
	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
}
MYSTRING::MYSTRING(const string s)
{
	len = s.length();
	str = new char[len];
	for (int i = 0; i < len; i++)
		str[i] = s[i];
}
MYSTRING::MYSTRING(const char *s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	str[len] = '\0';
}
MYSTRING::MYSTRING(int len)
{
	this->len = len;
	str = new char[len];
}
MYSTRING::~MYSTRING()
{
	delete [] str;
}
MYSTRING& MYSTRING::operator=(const MYSTRING &s)
{ 
	delete[]str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::operator=(const string&s)
{
	delete[] str;
	len = s.length();
	str = new char[len];
	for (int i = 0; i < len; i++)
		str[i] = s[i];
	return *this;
}
MYSTRING& MYSTRING::operator=(const char*c)
{
	delete[] str;
	len = strlen(c);
	str = new char[len];
	strcpy(str, c);
	return *this;
}
char* MYSTRING::begin()
{
	return &this->str[0];
}
int MYSTRING::size()
{
	return len;
}
int MYSTRING::length()
{
	return len;
}
void MYSTRING::resize(int n)
{
	str = (char*)realloc(str, (len + n+1)*sizeof(char));
	for (int i = len; i < len + n; i++)
		str[i] = ' ';
	str[len + n] = '\0';
	len = len + n;
}
void MYSTRING::resize(int n, char c)
{
	str = (char*)realloc(str, (len + n + 1)*sizeof(char));
	for (int i = len; i < len + n; i++)
		str[i] = c;
	str[len + n] = '\0';
	len = len + n;
}
int MYSTRING::capacity()
{
}
