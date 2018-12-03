#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <iostream>
using namespace std;
class MYSTRING
{ 
public:
	int len;
	char *str;
public:
	MYSTRING();
	MYSTRING(const MYSTRING &s);
	MYSTRING(const string s);
	MYSTRING(const char *s);
	MYSTRING(int len);
	~MYSTRING();
	MYSTRING& operator=(const MYSTRING&s);
	MYSTRING& operator=(const string&str);
	MYSTRING& operator=(const char* c);
	char* begin();
	int size();
	int length();
	void resize(int n);
	void resize(int n, char c);
	int capacity();
};
#endif
