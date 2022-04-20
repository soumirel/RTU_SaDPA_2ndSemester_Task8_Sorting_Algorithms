#pragma once

#include <thread>
#include <iostream>

class Timer
{
public:
	Timer();
	~Timer();

private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
};

