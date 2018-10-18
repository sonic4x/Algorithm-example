#include <iostream>
#include <iomanip>		// 主要是对cin,cout之类的一些操纵运算子，比如setfill,setw,setbase,setprecision等等
using namespace std;
 

 
 //8 x 8
 //     0     1     5     6    14    15    27    28
 //     2     4     7    13    16    26    29    42
 //     3     8    12    17    25    30    41    43
 //     9    11    18    24    31    40    44    53
 //    10    19    23    32    39    45    52    54
 //    20    22    33    38    46    51    55    60
 //    21    34    37    47    50    56    59    61
 //    35    36    48    49    57    58    62    63

 //先看矩阵，发现矩阵对角线上部元素与下部对应元素之和为N^2-1
 //即为 Arr[i][j]+Arr[N-1-i][N-1-j]=N^2-1
 //
 //所以我们只需要处理上三角即可，下三角可推出。
 //观察上三角中。
 //数组各项横纵坐标与值的关系
 //0  0  0
 //0  1  1
 //1  0  2
 //2  0  3
 //1  1  4
 //0  2  5
 //0  3  6
 //1  2  7
 //2  1  8
 //3  0  9
 //4  0  10
 //从中分析 发现（i+j）的和与结果有关系
 //令 s=i+j
 //s=0  只有0 1个元素落在这个范围
 //s=1  有2个
 //s=2  有3个
 //s=3  有4个
 //s=4  。。。
 //这样
 //任意一项Arr[i][j],令s=i+j
 //则该项之前的s-1项有
 //1+2+...+s=s(s+1)/2这么多个数，那么该数位于哪个位置?
 //我们再看看 添加其前s-1项的和
 //0  0  0   0
 //0  1  1   1
 //1  0  2   1
 //2  0  3   3
 //1  1  4   3
 //0  2  5   3
 //0  3  6   6
 //1  2  7   6
 //2  1  8   6
 //3  0  9   6
 //4  0  10  10
 //从中我们可以看出 ，当s能够被2整除时 Arr[i][j]=s(s+1)/2+j
 //否则 Arr[i][j]=s(s+1)/2+i;

 int main()
 {
     int N;
     int s,i,j;
     cout<<"Please Input The Number!"<<endl;
     cin>>N;

	 // create 2D array
     int** Arr=new int*[N];//int** Arr=(int **)malloc(N*sizeof(int));
     for(i=0;i<N;i++)
     {
		 Arr[i]=new int[N];//Arr[i]=(int*)malloc(N*sizeof(int));严格来讲这里应该加强防错处理。
	 }
	 /*
	 // 算法1：
	 // 上三角 xxxx
	 //		   xxx
	 //		   xx
	 //		   x
	 for(i=0;i<N;i++)
	 {
         for(j=0;j<N-i;j++)
         {
             s=i+j;
             if(s<N)
             {
                 Arr[i][j] = s*(s+1)/2 + ( (s%2==0) ? j:i );
             }
         }
	 }

	 // 下三角
	 for(i=N-1;i>0;i--)
	 {
             for(j=N-i;j<N;j++)
             {
                 Arr[i][j] = N*N -1 - Arr[N-1-i][N-1-j];
             }
	 }
	 */

	 //算法2：
	 for(i = 0; i < N; i++)
	 {
		 for(j = 0; j < N; j++)
		 { 
			 s = i + j;

			
			 if(s < N)//上三角
			 {
				/*
				每一斜线个数比上一行多一个，则每一斜线的第一个值表示了在该斜线之前元素的个数,即一个累加 ：（s+1）*s/2
				斜线中的任意元素可表示为s*（s+1）/2+i 或 s*（s+1）/2+j
				*/
				 s = i + j;
				 Arr[i][j] = s * (s + 1) / 2 + ((0 == (i + j) % 2) ? j : i);
			 }
			 else//下三角
			 {	
				 /*
				 每斜线的元素个数开始减少，等差数组不适用，为方便起见，可以用减法计算元素个数,
				 剩余元素的斜线数目：s1= (N - 1 - i) + (N - 1 - j);
				 元素值=（N*N-（s1+1）*s1/2）-（N-j）=下一斜线的第一个元素值-该斜线剩余元素的个数
				 */
				 s = (N - 1 - i) + (N - 1 - j);
				 Arr[i][j] = N*N - s * (s + 1) / 2 - (N - ((0 == (i + j) % 2) ? j : i));
			 }
		 }
	 }
     // traverse and print the whole array
     for(i=0;i<N;i++)
     {
         for(j=0;j<N;j++)
             cout<<setw(6)<<Arr[i][j];
         cout<<endl;
     }

	 while(1);
     return 0;
 }