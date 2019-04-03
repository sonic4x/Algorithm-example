#include "sum_sln.h"
#include "sum_sln2.h"
#include "sum_sln3.h"
#include "tuple_template.h"
#include <stdio.h>
#include <typeinfo>
#include <assert.h>
#include <tuple>

#include "sealedclass.h"
using namespace std;
int main()
{
#pragma region n sum
	int sum = sum_sln4<4>::N;
	printf("%d\n", sum);

	sum = nSum(4);
	printf("%d\n", sum);

	sum = sln3(4);
	printf("%d\n", sum);
#pragma endregion

#pragma region tuple sum
	
	typedef tuple< short, int> my_tuple;
	short first = 14;
	int second = 27;
	my_tuple t(first, second);
	auto rt = adding_func(std::get<0>(t), std::get<1>(t));
	printf("%d\n", rt);
	assert(typeid(rt) == typeid(int));
#pragma endregion

#pragma region Sealed class
	SealedClass sc;
	//SubClass sc2;
#pragma endregion

	getchar();

}