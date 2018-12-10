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
int MYSTRING::copy(char*s, int n, int pos)
{
	if (pos + n > len) return -1;
	int temp = 0;
	for (int i = pos; i < pos + n; i++)
	{
		s[temp] = str[i];
		temp++;
	}
	return temp;
}
int MYSTRING::find(const MYSTRING&s)
{
	int i = 0;
	while (i < len)
	{
		bool flag = true;
		int t = 0;
		for (int j = i; j < i + s.len; j++)
		{
			if (str[j] != s.str[t]) flag = false;
			t++;
		}
		if (flag == true) return i;
		else flag = false;
		i++;
	}
	return -1;
}
int MYSTRING::find(const char*s)
{
	int i = 0;
	while (i < len)
	{
		bool flag = true;
		int t = 0;
		for (int j = i; j < i + strlen(s); j++)
		{
			if (str[j] != s[t]) flag = false;
			t++;
		}
		if (flag == true) return i;
		else flag = false;
		i++;
	}
	return -1;
}
int MYSTRING::find(const char*s, int pos, int n)
{
	int i = pos;
	while (i < len)
	{
		bool flag = true;
		int t = 0;
		for (int j = i; j < i + n; j++)
		{
			if (str[j] != s[t]) flag = false;
			t++;
		}
		if (flag == true) return i;
		else flag = false;
		i++;
	}
	return -1;
}
int MYSTRING::find(char c)
{
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			return i;
			flag = true;
		}
	}
	if (flag == false) return -1;
}
int MYSTRING::rfind(const MYSTRING&s)
{
	int i = len-1;
	while (i >=0)
	{
		bool flag = true;
		int t = 0;
		for (int j = i; j < i + s.len; j++)
		{
			if (str[j] != s.str[t]) flag = false;
			t++;
		}
		if (flag == true) return i;
		else flag = false;
		i--;
	}
	return -1;
}
int MYSTRING::rfind(const char*s)
{
	int i = len-1;
	while (i >=0)
	{
		bool flag = true;
		int t = 0;
		for (int j = i; j < i + strlen(s); j++)
		{
			if (str[j] != s[t]) flag = false;
			t++;
		}
		if (flag == true) return i;
		else flag = false;
		i--;
	}
	return -1;
}
int MYSTRING::rfind(const char*s, int pos, int n)
{
	int i = len-1;
	while (i >=pos)
	{
		bool flag = true;
		int t = 0;
		for (int j = i; j < i + n; j++)
		{
			if (str[j] != s[t]) flag = false;
			t++;
		}
		if (flag == true) return i;
		else flag = false;
		i--;
	}
	return -1;
}
int MYSTRING::rfind(char c)
{
	bool flag = false;
	for (int i = len-1; i >=0; i--)
	{
		if (str[i] == c)
		{
			return i;
			flag = true;
		}
	}
	if (flag == false) return -1;
}
int MYSTRING::find_first_of(const MYSTRING&s)
{
	int i = 0;
	bool flag = false;
	while (i < len)
	{
		for (int j = 0; j < s.len;j++)
		if (str[i] == s.str[j])
		{
			flag = true;
			return i;
		}
		i++;
	}
	if (flag == false) return -1;
}
int MYSTRING::find_first_of(const char*s)
{
	int i = 0;
	bool flag = false;
	while (i < len)
	{
		for (int j = 0; j < strlen(s); j++)
		if (str[i] == s[j])
		{
			flag = true;
			return i;
		}
		i++;
	}
	if (flag == false) return -1;
}
int MYSTRING::find_first_of(const char*s, int pos, int n)
{
	int i = 0;
	bool flag = false;
	while (i < len)
	{
		for (int j = 0; j < n; j++)
		if (str[i] == s[j])
		{
			flag = true;
			return i;
		}
		i++;
	}
	if (flag == false) return -1;
}
int MYSTRING::find_first_of(char c)
{
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			return i;
			flag = true;
		}
	}
	if (flag == false) return -1;
}
int MYSTRING::find_last_of(const MYSTRING&s)
{
	int i = len-1;
	bool flag = false;
	while (i >=0)
	{
		for (int j = 0; j < s.len; j++)
		if (str[i] == s.str[j])
		{
			flag = true;
			return i;
		}
		i--;
	}
	if (flag == false) return -1;
}
int MYSTRING::find_last_of(const char*s)
{
	int i = len-1;
	bool flag = false;
	while (i >=0)
	{
		for (int j = 0; j < strlen(s); j++)
		if (str[i] == s[j])
		{
			flag = true;
			return i;
		}
		i--;
	}
	if (flag == false) return -1;
}
int MYSTRING::find_last_of(const char*s, int pos, int n)
{
	int i = len-1;
	bool flag = false;
	while (i >=0)
	{
		for (int j = 0; j < n; j++)
		if (str[i] == s[j])
		{
			flag = true;
			return i;
		}
		i--;
	}
	if (flag == false) return -1;
}
int MYSTRING::find_last_of(char c)
{
	bool flag = false;
	for (int i = len-1; i >=0; i--)
	{
		if (str[i] == c)
		{
			return i;
			flag = true;
		}
	}
	if (flag == false) return -1;
}
int MYSTRING::find_first_not_of(const MYSTRING&s)
{
	int i = 0;
	bool flag = false;
	while (i < len)
	{
		flag = false;
		for (int j = 0; j < s.len; j++)
		if (str[i] == s.str[j])
		{
			flag = true;
		}
		if (flag == false) return i;
		i++;
	}
	if (flag == true) return -1;
}
int MYSTRING::find_first_not_of(const char*s)
{
	int i = 0;
	bool flag = false;
	while (i < len)
	{
		flag = false;
		for (int j = 0; j < strlen(s); j++)
		if (str[i] == s[j])
		{
			flag = true;
		}
		if (flag == false) return i;
		i++;
	}
	if (flag == true) return -1;
}
int MYSTRING::find_first_not_of(const char*s, int pos, int n)
{
	int i = 0;
	bool flag = false;
	while (i < len)
	{
		flag = false;
		for (int j = 0; j < n; j++)
		if (str[i] == s[j])
		{
			flag = true;
		}
		if (flag == false) return i;
		i++;
	}
	if (flag == true) return -1;
}
int MYSTRING::find_first_not_of(char c)
{
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != c)
		{
			return i;
			flag = true;
		}
	}
	if (flag == false) return -1;
}
int MYSTRING::find_last_not_of(const MYSTRING&s)
{
	int i = len-1;
	bool flag = false;
	while (i >=0)
	{
		flag = false;
		for (int j = 0; j < s.len; j++)
		if (str[i] == s.str[j])
		{
			flag = true;
		}
		if (flag == false) return i;
		i--;
	}
	if (flag == true) return -1;
}
int MYSTRING::find_last_not_of(const char*s)
{
	int i = len-1;
	bool flag = false;
	while (i >=0)
	{
		flag = false;
		for (int j = 0; j < strlen(s); j++)
		if (str[i] == s[j])
		{
			flag = true;
		}
		if (flag == false) return i;
		i--;
	}
	if (flag == true) return -1;
}
int MYSTRING::find_last_not_of(const char*s, int pos, int n)
{
	int i = len-1;
	bool flag = false;
	while (i >=0)
	{
		flag = false;
		for (int j = 0; j < n; j++)
		if (str[i] == s[j])
		{
			flag = true;
		}
		if (flag == false) return i;
		i--;
	}
	if (flag == true) return -1;
}
int MYSTRING::find_last_not_of(char c)
{
	bool flag = false;
	for (int i = len-1; i >=0; i--)
	{
		if (str[i] != c)
		{
			return i;
			flag = true;
		}
	}
	if (flag == false) return -1;
}
MYSTRING MYSTRING::substr(int pos, int n)
{
	MYSTRING a;
	a.len = n;
	a.str = new char[a.len+1];
	int temp = 0;
	for (int i = pos; i < pos + n; i++)
	{
		a.str[temp] = str[i];
		temp++;
	}
	a.str[a.len] = '\0';
	cout << a.str << endl;
	return a;
}
int MYSTRING::compare(const MYSTRING&s) const
{
	return strcmp(str, s.str);
}
int MYSTRING::compare(int pos, int n, const MYSTRING&s) const
{
	if (n < s.len) return -1;
	if (n > s.len) return 1;
	MYSTRING a = *this;
	a.append(a, pos, n);
	return strcmp(a.str, s.str);
}
int MYSTRING::compare(int pos, int n, const MYSTRING&s, int subpos, int subn) const
{
	if (n < subn) return -1;
	if (n>subn) return 1;
	MYSTRING a = *this;
	MYSTRING b = s;
	a.append(a,pos, n);
	b.append(b, subpos, subn);
	return strcmp(a.str, b.str);
}
int MYSTRING::compare(const char*s) const
{
	return strcmp(str, s);
}
int MYSTRING::compare(int pos, int n, const char*s) const
{
	if (n < strlen(s)) return -1;
	if (n > strlen(s)) return 1;
	MYSTRING a = *this;
	a.append(a, pos, n);
	return strcmp(a.str, s);
}
int MYSTRING::compare(int pos, int n, const char*s, int subn) const
{
	if (n < subn) return -1;
	if (n>subn) return 1;
	MYSTRING a = *this;
	a.append(a, pos, n);
	char*b = new char[subn + 1];
	for (int i = 0; i < subn; i++) b[i] = s[i];
	b[subn] = '\0';
	return strcmp(a.str, b);
}
istream& MYSTRING::getline(istream& is, MYSTRING& str, char delim)
{
	char ch = 0;
	istream& get(char& ch);
	while (is && ch != delim)
	{
		istream& get(char& ch);
		str += ch;
	};
	return is;
}
