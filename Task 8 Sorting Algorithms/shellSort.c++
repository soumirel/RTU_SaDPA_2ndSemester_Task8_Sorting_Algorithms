#include "ShellSort.h"

void shellSort(int* p_array, const size_t& size)
{
	Timer newTimer;

	for (size_t d = size / 2; d > 0; d /= 2) 
	{
		for (size_t i = d; i < size; ++i) 
		{
			for (int j = i - d; j >= 0 && p_array[j] > p_array[j + d]; j -= d) 
			{
				std::swap(p_array[j], p_array[j + d]);
			}
		}
	}
}
