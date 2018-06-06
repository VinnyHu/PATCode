#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	while(scanf("%d:%d:%d",&a,&b,&c))
	{
		 d = a * 3600 + b * 60 + c;
		cout<<d<<endl;	
		int a1 = d/3600;
		cout<<a1<<endl;
	}

	
	return 0;
} 
