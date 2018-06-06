#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;
struct Campus
{
	char car_number[10];
	int time;
	char status[5];
} Record[11111];
struct Final
{
	char car_number[10];
	int stop_time;
	int in_time;
	int out_time;
} Car[11111];
struct Time
{
	int time = 0;
} MM[11111];
int cmp(Campus A,Campus B)
{
	if(strcmp(A.car_number,B.car_number)!=0)
		return strcmp(A.car_number,B.car_number) < 0;
	else 
		return A.time < B.time;
}

int count_number(int time,int count)
{
	int num = 0;
	for(int i = 0;i < count;i++)
	{
		if(time>=Car[i].in_time&&time<Car[i].out_time)
		{
			num++;
		}
	}
	return num;
}
int main()
{
	int query[80008];
	int N,K;
	string num,status;
	int hh,mm,ss;
	scanf("%d%d",&N,&K);
	for(int i = 0;i<N;i++)
	{
		scanf("%s%d:%d:%d%s",Record[i].car_number,&hh,&mm,&ss,Record[i].status);
		Record[i].time = hh * 3600 + mm * 60 + ss;
	}
	for(int i = 0;i<K;i++)
	{
		scanf("%d:%d:%d",&hh,&mm,&ss);
		query[i] = hh * 3600 + mm * 60 + ss;
	}
	sort(Record,Record+N,cmp);
	int count = 0;
	int count1 = 0;
	for(int i = 0;i<N;i++)
	{
		if(strcmp(Record[i].status,"in") == 0)
		{
			
			if((i+1) < N && strcmp(Record[i+1].status,"out") == 0 && strcmp(Record[i].car_number,Record[i+1].car_number) == 0)
			{
				strcpy(Car[count].car_number,Record[i].car_number);
				Car[count].in_time = Record[i].time;
				Car[count].out_time = Record[i+1].time;
				Car[count].stop_time = Record[i+1].time - Record[i].time;
				
				count ++;
			}
		}
	}
	for(int i = 0;i<K;i++)
	{
		cout<<count_number(query[i],count)<<endl;
	}
	
	int time = 0;
	for(int i = 0;i<count;i++)
	{
		int temp_time = 0;
		for(int j = i;j<count&&strcmp(Car[j].car_number,Car[i].car_number) == 0;j++)
		{
			temp_time += Car[j].stop_time;
		}
		if(temp_time > time)
		{
			time = temp_time;
		}
		
	}
	for(int i = 0;i<count;i++)
	{
		int temp_time = 0;
		for(int j = i;j<count&&strcmp(Car[j].car_number,Car[i].car_number) == 0;j++)
		{
			temp_time += Car[j].stop_time;
		}
		if(temp_time == time)
		{
			printf("%s ",Car[i].car_number);
		}
	}
	int a[3];
	a[0] = time / 3600;
	a[1] = (time - a[0]*3600)/60;
	a[2] = time - a[0] * 3600 - a[1] * 60;
	for(int i = 0;i < 2;i++)
	{
		if(a[i]<10)
		{
			printf("0%d:",a[i]);
		}
		else
		{
			printf("%d:",a[i]);
		}
	}
	if(a[2]<10)
	{
		printf("0%d",a[2]);
	}
	else
	{
		printf("%d",a[2]);
	}
	printf("\n");
	return 0;
}
