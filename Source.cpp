#include <iostream>
using namespace std;
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
MYSTRING& MYSTRING::operator=(const char*c)
{
	delete[] str;
	len = strlen(c);
	str = new char[len];
	strcpy(str, c);
	return *this;
}
MYSTRING::iterator MYSTRING::begin()
{
	return str;
}
MYSTRING::iterator MYSTRING::end()
{
	return str+len;
}
char* MYSTRING::rbegin()
{
	char *temp = new char[len];
	for (int i = len - 1; i >= 0; i--)
	{
		temp[len-i-1] = str[i];
	}
	temp[len] = '\0';
	return &temp[0];
}
char * MYSTRING::rend()
{
	char *temp = new char[len];
	for (int i = len - 1; i >= 0; i--)
	{
		temp[len - i - 1] = str[i];
	}
	temp[len] = '\0';
	return &temp[len];
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
	int i = 0;
	while (str)
	{ 
		i++; 
		*str++; 
	}
	return i;
}
void MYSTRING::clear()
{
	len = 1;
	str = new char[len];
	*str = '\0';
}
bool MYSTRING::empty()
{
	if (!*str) return true;
	return false;
}
char& MYSTRING::operator[](int n)
{
	return str[n];
}
char MYSTRING::at(int n)
{
	return str[n];
}
char MYSTRING::back()
{
	return str[0];
}
char MYSTRING::front()
{
	return str[len - 1];
}
MYSTRING& MYSTRING::operator+=(const MYSTRING&s)
{
	str = (char*)realloc(str, (len + s.len+1)*sizeof(char));
	strcat(str, s.str);
	len =len+ s.len;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::operator+=(const char*s)
{
	str = (char*)realloc(str, (len + strlen(s)+1)*sizeof(char));
	len = len + strlen(s);
	strcat(str, s);
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::append(const MYSTRING&s)
{
	str = (char*)realloc(str, (len + s.len + 1)*sizeof(char));
	int temp = 0;
	for (int i = len; i < len + s.len; i++)
	{
		str[i] = s.str[temp];
		temp++;
	}
	len = len + s.len;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::append(const MYSTRING &s, int pos, int n)
{
	str = (char*)realloc(str, (len + n + 1)*sizeof(char));
	int temp = pos;
	for (int i = len; i < len + n; i++)
	{
		if (temp < pos + n)
		{
			str[i] = s.str[temp];
			temp++;
		}
	}
	len = len + n;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::append(const char *s)
{
	str = (char*)realloc(str, (len + strlen(s) + 1)*sizeof(char));
	len = len + strlen(s);
	strcat(str, s);
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::append(const char*s, int n)
{
	str = (char*)realloc(str, (len + n + 1)*sizeof(char));
	int temp = 0;
	for (int i = len; i < len + n; i++)
	{
		if (temp < n)
		{
			str[i] = s[temp];
			temp++;
		}
	}
	len = len + n;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::append(int n, char c)
{
	str = (char*)realloc(str, (len + n + 1)*sizeof(char));
	for (int i = len; i < len + n; i++)
	{
		str[i] = c;
	}
	len = len + n;
	str[len] = '\0';
	return *this;
}

void MYSTRING::push_back(char c)
{
	len = len + 1;
	str = (char*)realloc(str, (len+1)*sizeof(char));
	str[len-1] = c;
	str[len] = '\0';
}
MYSTRING& MYSTRING::assign(const MYSTRING&s)
{
	delete[] str;
	len = s.len;
	str = new char[len+1];
	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::assign(const MYSTRING&s, int pos, int n)
{
	delete[] str;
	len = n;
	str = new char[n + 1];
	int temp = 0;
	for (int i = pos; i < pos + n; i++)
	{
		str[temp] = s.str[i];
		temp++;
	}
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::assign(const char*s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
		str[i] = s[i];
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::assign(const char*s, int n)
{
	delete[] str;
	len = n;
	str = new char[n + 1];
	for (int i = 0; i < len; i++)
		str[i] = s[i];
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::assign(int n, char c)
{
	delete[] str;
	len = n;
	str = new char[n + 1];
	for (int i = 0; i < len; i++)
		str[i] = c;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::insert(int pos, const MYSTRING&s)
{
	str = (char*)realloc(str, (len + s.len + 1)*sizeof(char));
	for (int i = len; i<len+s.len; i++)
	{
		for (int j = i; j > pos; j--)
		{
			str[j] = str[j - 1];
		}
	}
	int temp = 0;
	for (int i = pos; i < pos + s.len; i++)
	{
		str[i] = s.str[temp];
		temp++;
	}
	len = len + s.len;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::insert(int pos, const MYSTRING&s, int subpos, int n)
{
	str = (char*)realloc(str, (len + n + 1)*sizeof(char));
	for (int i = len; i<len + n; i++)
	{
		for (int j = i; j > pos; j--)
		{
			str[j] = str[j - 1];
		}
	}
	int temp = subpos;
	for (int i = pos; i < pos + s.len; i++)
	{
		if (temp < subpos + n)
		{
			str[i] = s.str[temp];
			temp++;
		}
	}
	len = len + n;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::insert(int pos, const char*s)
{
	str = (char*)realloc(str, (len + strlen(s) + 1)*sizeof(char));
	for (int i = len; i<len + strlen(s); i++)
	{
		for (int j = i; j > pos; j--)
		{
			str[j] = str[j - 1];
		}
	}
	int temp = 0;
	for (int i = pos; i < pos + strlen(s); i++)
	{
		str[i] = s[temp];
		temp++;
	}
	len = len + strlen(s);
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::insert(int pos, const char*s, int n)
{
	str = (char*)realloc(str, (len + n + 1)*sizeof(char));
	for (int i = len; i<len + n; i++)
	{
		for (int j = i; j > pos; j--)
		{
			str[j] = str[j - 1];
		}
	}
	int temp = 0;
	for (int i = pos; i < pos + n; i++)
	{
		if (temp <n)
		{
			str[i] = s[temp];
			temp++;
		}
	}
	len = len + n;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::insert(int pos, int n, char c)
{
	str = (char*)realloc(str, (len + n + 1)*sizeof(char));
	for (int i = len; i<len + n; i++)
	{
		for (int j = i; j > pos; j--)
		{
			str[j] = str[j - 1];
		}
	}
	int temp = 0;
	for (int i = pos; i < pos + n; i++)
	{
		if (temp <n)
		{
			str[i] = c;
			temp++;
		}
	}
	len = len + n;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::erase(int pos, int n)
{
	int temp = 0;
	for (int j = pos; j < len-1,temp<=n;j++)
	{
		str[j] = str[j + 1];
		temp++;
	}
	len = len - n;
	str[len] = '\0';
	return *this;
}
MYSTRING& MYSTRING::replace(int pos, int n, const MYSTRING&s)
{
	
	return *this;
}
MYSTRING& MYSTRING::replace(int pos, int n, const MYSTRING&s, int subpos, int subn)
{
	return *this;
}
MYSTRING& MYSTRING::replace(int pos, int n, const char *s)
{
	return *this;
}
MYSTRING& MYSTRING::replace(int pos, int n, int len, char c)
{
	return *this;
}
void MYSTRING::swap(MYSTRING&s)
{
	MYSTRING temp = *this;
	delete[] str;
	len = s.len;
	str = new char[len+1];
	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
	str[len] = '\0';
	delete[] s.str;
	s.len = temp.len;
	s.str = new char[s.len+1];
	for (int i = 0; i < temp.len; i++)
		s.str[i] = temp.str[i];
	s.str[s.len] = '\0';
}
void MYSTRING::pop_back()
{
	len = len - 1;
	str = (char*)realloc(str, (len + 1)*sizeof(char));
	str[len] = '\0';
}
