#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int a[3],b[3],c[3];
	scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
	scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
	c[0] = c[1] = c[2] = 0;
	int num1;
	if(a[2]+b[2]>=29)
	{
		num1 = 1;
		c[2] = a[2]+b[2] - 29;
	}
	else
	{
		c[2] = a[2]+b[2];
		num1 = 0;
	}
	a[1] += num1;
	if(a[1]+b[1]>=17)
	{
		c[1] = a[1] + b[1] -17;
		num1 = 1;
	}
	else
	{
		c[1] = a[1] + b[1];
		num1 = 0;
	}
	a[0] += num1;
	c[0] = a[0] + b[0];
	printf("%d.%d.%d",c[0],c[1],c[2]);
	return 0;
} 
