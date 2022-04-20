#include "BubbleIversonSort.h"

void bubbleIversonSort(int* p_array, const size_t& size)
{
	Timer newTimer;

	bool iversonCondition;
	for (size_t i = size; i > 1; i--)
	{
		iversonCondition = true;
		for (size_t j = 0; j < i - 1; j++)
			if (p_array[j] > p_array[j + 1])
			{
				std::swap(p_array[j], p_array[j + 1]);
				iversonCondition = false;
			};
		if (iversonCondition)
		{
			return;
		}
	};

	return;
}