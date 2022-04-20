#include "Timer.h"

Timer::Timer()
{
	start = std::chrono::high_resolution_clock::now();
}


Timer::~Timer()
{
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Время выполнения: " << duration.count() << " сек.\n";
}