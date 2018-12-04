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
	MYSTRING(const char *s);
	MYSTRING(int len);
	~MYSTRING();
	MYSTRING& operator=(const MYSTRING&s);
	MYSTRING& operator=(const char* c);
	char* begin();
	char *end();
	char* rbegin();
	char *rend();
	int size();
	int length();
	void resize(int n);
	void resize(int n, char c);
	int capacity();
	void clear();
	bool empty();
	char& operator[](int n);
	char at(int n);
	char back();
	char front();
	MYSTRING& operator+=(const MYSTRING&s);
	MYSTRING& operator+=(const char*s);
	MYSTRING& append(const MYSTRING&s);
	MYSTRING& append(const MYSTRING &s, int pos, int n);
	MYSTRING& append(const char *s);
	MYSTRING& append(const char*s, int n);
	MYSTRING& append(int n, char c);
	void push_back(char c);
	MYSTRING& assign(const MYSTRING&s);
	MYSTRING& assign(const MYSTRING&s, int pos, int n);
	MYSTRING& assign(const char*s);
	MYSTRING& assign(const char*s, int n);
	MYSTRING& assign(int n, char c);
	MYSTRING& insert(int pos, const MYSTRING&s);
	MYSTRING& insert(int pos, const MYSTRING&s, int subpos, int n);
	MYSTRING& insert(int pos, const char*s);
	MYSTRING& insert(int pos, const char*s, int n);
	MYSTRING& insert(int pos, int n, char c);
	MYSTRING& erase(int pos, int n);
};
#endif
