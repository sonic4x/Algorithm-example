# include <iostream.h>
# include <iomanip.h>
# define M 4
# define N 3
int array[M][N],b[N][M];
void fun(int array[M][N],int b[N][M])
{
	int i,j;
	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
		{
			b[j][i]=array[i][j];
		}
}

void main()
{
	int i,j;
	cout<<"输入数组元素："<<endl;
	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
			cin>>array[i][j];
	cout<<" 数组是："<<endl;
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
			cout<<setw(5)<<array[i][j]<<"  ";
		cout<<endl;
	}
	fun(array,b);
	cout<<"转置后数组是： "<<endl;
    for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
			cout<<setw(5)<<b[i][j]<<"  ";
		cout<<endl;
	}
}
