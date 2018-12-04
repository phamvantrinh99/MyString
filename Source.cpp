#include <stdio.h>
#include <cstring>
#include <stdlib.h>
void main()
{
	int n;
	char s[255]="";
	printf("Nhap n: ");
	scanf("%d", &n);
	int t=0,a[100];
	while (n / 1000 != 0)
	{
		a[t] = n % 1000;
		t++;
		n = n / 1000;
	}
	a[t] = n;
	for (int i = t; i >=0; i--)
	{
		char temp[10];
		itoa(a[i], temp, 10);
		strcat(s, temp);
		if (i!=0) strcat(s, ",");
		else;
	}
	printf("%s\n", s);
}
