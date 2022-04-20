#include "MergeSort.h"

int* sort(int* source, int* buff, size_t left, size_t right)
{

	if (left == right)
	{
		buff[left] = source[left];
		return buff;
	}

	size_t middle = left + (right - left) / 2;

	int* l_buff = sort(source, buff, left, middle);
	int* r_buff = sort(source, buff, middle + 1, right);

	// слияние двух отсортированных половин
	int* target = l_buff == source ? buff : source;

	size_t l_cur = left, r_cur = middle + 1;
	for (size_t i = left; i <= right; i++)
	{
		if (l_cur <= middle && r_cur <= right)
		{
			if (l_buff[l_cur] < r_buff[r_cur])
			{
				target[i] = l_buff[l_cur];
				l_cur++;
			}
			else
			{
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= middle)
		{
			target[i] = l_buff[l_cur];
			l_cur++;
		}
		else
		{
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}

	return target;
}


void mergeSort(int* source, size_t size)
{
	Timer newTimer;

	int* bufferArray = new int[size];

	source = sort(source, bufferArray, 0, size - 1);
}