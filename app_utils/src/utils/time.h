#include <iostream>
#include <chrono>

namespace utils
{
    class Time
    {
    public:
        uint64_t getEpocTimeInNanoseconds();
        uint64_t getEpocTimeInMicroseconds();
        uint64_t getEpocTimeInMilliseconds();
        uint64_t getEpocTimeInSeconds();
        uint64_t getEpocTimeInMinutes();

        void printNowTime();
    };
}