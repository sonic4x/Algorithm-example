#include <iostream.h>
void main()
{
	int i,k,m,s,sh,num[30],sea[15],ship[15];
	for (i=0;i<30;i++)
	num[i]=i+1;  //1��30��ÿ�˱��
	i=0;  //iΪÿ��ѭ��ʱ��������
	k=0;  //kΪ��1��2...9����ʱ��������
	m=0;  //mΪ�˳�����
	s=0;  //�汻Ͷ�뺣��������±�
	sh=0;  //���ڴ����˱��������±�
	while (m<15)
	{
		if (num[i]!=0) k++;
		if (k==9)
		{
			sea[s]=num[i];
			s++;
			num[i]=0;
			k=0;
			m++;
		}
		i++;
		if (i==30) i=0;
	}
	for(i=0;i<30;i++)
		if (num[i]!=0)
		{
		ship[sh]=num[i];
		sh++;
		}

	cout<<"��Ͷ�뺣�����Ϊ��"<<endl;
	for(i=0;i<15;i++)
	{
	    cout<<sea[i]<<"  ";
	}
    cout<<endl<<"���ڴ��ϵ����Ϊ��"<<endl;
    for(i=0;i<15;i++)
	{
	   	cout<<ship[i]<<"  ";
	}
	cout<<endl;
}
