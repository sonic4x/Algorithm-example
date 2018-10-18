# include <stdio.h>
# include <math.h>
# include <conio.h>

void printmonth(int m);
void printhead(int m);
int daysofmonth(int m);
int firstday(int y);
int year,weekday;

void main()
{
	int i;
	printf("��������ݣ�");
	scanf("%d",& year);
	weekday=firstday(year);
	printf("\n\n");
	printf("                 %d��\n",year); 
	for(i=1;i<=12;i++)
	{
		printmonth(i);
		printf("\n");
	}
	printf("\n\n");
	getch();
}

void printmonth(int m)  //��ӡÿ������
{
	int i,days;
	printhead(m);
	days=daysofmonth(m);
	for(i=1;i<=days;i++)
	{
		printf("%5d",i);
		weekday=(weekday+1)%7;
		if (weekday==0) printf("\n   ");
	}
}
void printhead(int m) //��ӡÿ�µ�����ͷ���ж���ʼλ�ã�
{
	int i;
	printf("\n%d��   ��   һ   ��   ��   ��   ��   ��\n",m);
	printf("   ");
	for(i=0;i<weekday;i++)
		printf("     ");
}
int daysofmonth(int m)  //ÿ�µ�����
{
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:return 31;
	case 4:
	case 6:
	case 9:
	case 11:return 30;
	case 2:if (((year%4==0 && year%100!=0)||year%400==0))
			   return 29;
		   else 
			   return 28;
	default: return 0;
	}
}
int firstday(int y)  //�ж�ĳ��Ԫ�������ڼ�
{
	double s ;
	s=floor(year-1+(year-1)/4.0-(year-1)/100.0+(year-1)/400.0+1);
	return (int)s%7;
}
