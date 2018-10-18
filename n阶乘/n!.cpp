//�׳˸��㷨�� C++ ��ʵ��
#include <iostream>
#include <cstring>
#include <iomanip> 
#include <cmath> 
using namespace std;
 
static const int MAXN = 5001;                          // ���׳�����ʵ���ò�����ô�� 

class Factorial {
    int *data[MAXN];                                            // ��Ÿ������Ľ׳�
    int *nonzero;                                                 // �ӵ�λ�����һ����0���� 
    int maxn;                                                       // �������Ѿ�����õ�n�Ľ׳� 
    
	int SmallFact(int n);                                         // n <= 12�ĵݹ����
	int SmallFact2(int n);										// �ǵݹ�ʵ��
    void TransToStr(int n, int *s);                           // ����n������������� 
    void Multply (int* A, int* B, int* C, int totallen);   // ִ�������߾������ĳ˷�
public:
    Factorial();
    ~Factorial();
    void Calculate(int n);                                       // ���ü���׳� 
    int FirstNonZero(int n);                                    // ���ؽ׳�ĩβ��һ����0���� 
    int CountZeros(int n);                                     // ���ؽ׳�ĩβ�ж��ٸ�0 
    int SecondNum(int n);                                    // ���ؽ׳���ߵĵڶ������� 
    bool CanDivide(int m, int n);                            // �ж���ֵ m �Ƿ�������� n! 
    void Output(int n) const;
}; 
   
int Factorial::SmallFact(int n)								
{
    if (n == 1 || n == 0) return 1;
    return SmallFact(n-1)*n;
}    
 
int Factorial::SmallFact2(int n)
{
	int dwRes = n;
	while ( n > 2)
	{
		dwRes *= (--n);
	}
	return dwRes;
}

void Factorial::TransToStr(int n, int *tmp) {
    int i = 1;
    while (n) {
        tmp[i++] = n%10;
        n /= 10;
    }    
    tmp[0] = i-1;
}   
 
void Factorial::Multply (int* A, int* B, int* C, int totallen) 
{
    int i, j, len;    
    memset(C, 0, totallen*sizeof(int));    
    for (i = 1; i <= A[0]; i++)
    for (j = 1; j <= B[0]; j++) {
        C[i+j-1] += A[i]*B[j];                                 // ��ǰi+j-1λ��Ӧ�� + A[i] * B[j]
        C[i+j] += C[i+j-1]/10;                                // ���ĺ�һλ + �����̣���λ�� 
        C[i+j-1] %= 10;                                        // ����ȡ�༴�� 
    }
    len = A[0] + B[0];    
    while (len > 1 && C[len] == 0 ) len--;             // �������ʵ�ʳ��� 
    C[0] = len;   
}  
 
Factorial::Factorial() {                                       // ���캯�����Ȱ�<=12�Ľ׳˼���� 
    maxn = 12; data[0] = new int [2];
    data[0][0] = 1; data[0][1] = 1;
    int i, j = 1;
    for (i = 1; i <= 12; i++) {
        data[i] = new int [12];
        j = j*i;
        TransToStr(j, data[i]);
    }    
    nonzero = new int [10*MAXN];
    nonzero[0] = 1; nonzero[1] = 1;                  // nonzero[0]�洢�Ѿ����㵽��n!ĩβ��0�� 
}
 
Factorial::~Factorial() {
    for (int i = 0; i <= maxn; i++)
        delete [] data[i];
    delete [] nonzero; 
}    
 
void Factorial::Calculate(int n) {
    if (n > MAXN)  return;     
    if (n <= maxn) return;                               // <= maxn�ģ��Ѿ��ڼ���õ��������� 
    int i, j, len;
    int tmp[12];
    for (i = maxn+1; i <= n; i++) {
        TransToStr(i, tmp);
        len = data[i-1][0] + tmp[0] + 1;
        data[i] = new int [len+1];
        Multply(data[i-1], tmp, data[i], len+1);
    }
    maxn = n;
}
 
int Factorial::FirstNonZero(int n) {
    if (n >= 10*MAXN) {
        cout << "Super Pig, your input is so large, cannot Calculate. Sorry!\n";
        return -1;
    }     
    if (n <= nonzero[0]) return nonzero[n];      //�Ѿ�������ˣ�ֱ�ӷ���

    int res[5][4] = {{0,0,0,0}, {2,6,8,4}, {4,2,6,8}, {6,8,4,2}, {8,4,2,6}};
    int i, five, t;
    for (i = nonzero[0]+1; i <= n; i++) {
        t = i;
        while (t%10 == 0) t /= 10;                  // ��ȥ�� i ĩβ�� 0�����ǲ�Ӱ��� 
        if (t%2 == 0) {                                   // t��ż��ֱ�ӳ���ȡģ10���� 
            nonzero[i] = (nonzero[i-1]*t)%10; 
        }     
        else {                                                // ����ת���� res �������� 
            five = 0;
            while (t%5 == 0) {
                if (five == 3) five = 0;
                else five++;
                t /= 5; 
            }     
            nonzero[i] = res[((nonzero[i-1]*t)%10)/2][five];
                            // (nonzero[i-1]*t)%10/2 �������Ϊ��1, 2, 3, 4 �е�һ�� 
        }     
    } 
    nonzero[0] = n; 
    return nonzero[n]; 
}  
 
/* �׳�ĩβ�ж��ٸ�0��ʵ����ֻ��5�����������йأ����� n/5+n/25+n/625+...... */
int Factorial::CountZeros(int n) {
    if (n >= 2000000000) {
        cout << "Super Pig, your input is so large, cannot Calculate. Sorry!\n";
        return -1;
    }   
    int cnt = 0;
    while (n) {
        n /= 5;
        cnt += n;
    }
    return cnt; 
} 
 
/*  ���N!��ߵڶ�λ�����֣���ʵ���ˣ�����100�ͳ���10�����ȡ��λ����  */
int Factorial::SecondNum(int n) {
    if (n <= 3) return 0; 
    int i; 
    double x = 6;
    for (i = 4; i <= n; i++) {
        x *= i;
        while (x >= 100) x /= 10; 
    }
    return (int(x))%10; 
}     
 
bool Factorial::CanDivide(int m, int n) {
    if (m == 0) return false;
    if (n >= m) return true; 
    int nn, i, j, nums1, nums2;
    bool ok = true; 
    j = (int)sqrt(1.0*m);
    for (i = 2; i <= j; i++) {
        if (m%i == 0) {
            nums1 = 0;                                       // ����m��������i������ 
            while (m%i == 0) {
                nums1++;
                m /= i;
            } 
            nums2 = 0; nn = n; 
            while (nn) {                                      // �� n ���� i ���ӵ����� 
                nn /= i;
                nums2 += nn; 
            }  
            if (nums2 < nums1) {                        // ����m������i����������m�϶��޷�����n! 
                ok = false;
                break; 
            }   
            j = (int)sqrt(1.0*m);                         // �����µ�������ǰ����Χ 
        }    
    } 
    if (!ok || m > n || m == 0) return false; 
    else return true; 
}      
 
void Factorial::Output(int n) const {
    if (n > MAXN) {
        cout << "Super Pig, your input is so large, cannot Calculate. Sorry!\n";
        return;
    }     
    int i, len = 8;
    cout << setw(4) << n << "! = ";              // ��ʽ������� 
    for (i = data[n][0]; i >= 1; i--) {
        cout << data[n][i];
        if (++len == 58) {                               // ʵ��ÿ���50���ַ��ͻ��� 
            len = 8;
            cout << "\n        ";
        }    
    }    
    if (len != 8) cout << endl;
}    
 
//C�ݹ�ʵ�ַ�
int factorial_recursive(int n)
{
	int dwRes;
	if (n == 0 || n == 1)
	{
		dwRes = 1;
	}
	else
	{
		dwRes = n * factorial_recursive(n-1);
	}
	
	return dwRes;
} 

int main() 
{
	//C++ ��ʵ��
	
    int n, m, i;
    Factorial f;
    while (cin >> n) {
        f.Calculate(n);
        f.Output(n);
        cout << "�ý׳�ĩβ��һ����0������: " << f.FirstNonZero(n) << endl; 
        cout << "�ý׳��ܹ�ӵ������0�ĸ�����" << f.CountZeros(n) << endl;
        cout << "�ý׳˵���ߵĵ�2λ�����ǣ�" << f.SecondNum(n) << endl; 
        cin >> m;
        if (f.CanDivide(m, n)) cout << m << " �������� " << n << "!\n";
        else cout << m << " �������� " << n << "!\n";  
    }
	

	//�ҵ�ʵ�ַ���
	/*
	int dwIn;
	cin >> dwIn;
	int dwRes = dwIn;
	while ( dwIn > 2)
	{
		dwRes *= (--dwIn);
	}
	cout << dwIn <<" �׳�Ϊ��"<< dwRes << endl;
	*/

	//�ݹ�ʵ�ַ���
	/*
	int dwIn;
	cout << "input the number:" << endl;
	cin >> dwIn;
	int dwRes = factorial_recursive(dwIn);
	cout << dwIn <<" �׳�Ϊ��"<< dwRes << endl;
	*/

    return 0;    
}

