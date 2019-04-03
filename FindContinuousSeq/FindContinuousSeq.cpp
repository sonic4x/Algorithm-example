#include <stdio.h>
#include <chrono>
void PrintSeq(int small, int big)
{
	int i = small;
	for (; i <= big; ++i)
	{
		printf("%d\t", i);
	}
	printf("\n");
}
void FindContinuousSeq(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;

	int curSum = 3;
	int smallMax = sum >> 1;
	int bigMax = smallMax + 1;

	while (small <= smallMax
		&& big <= bigMax
		&& small < big)
	{

		if (curSum == sum) {
			PrintSeq(small, big);
			big++;
			curSum += big;
		}
		else if (curSum < sum) {
			big++;
			curSum += big;
		}
		else {
			curSum -= small;
			small++;
		}
			
	}
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	FindContinuousSeq(15);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	printf("Total time is %fs\n", elapsed.count());


	getchar();
}