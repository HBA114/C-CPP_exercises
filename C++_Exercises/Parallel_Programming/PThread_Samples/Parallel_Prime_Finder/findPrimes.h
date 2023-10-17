#ifndef FINDPRIMES
#define FINDPRIMES

#include <chrono>
#include <iostream>
#include <pthread.h>

using namespace std;

struct SearchRangeStruct
{
    int start;
    int end;
};

chrono::_V2::system_clock::time_point startTime;

// Forward Declaration
void StartTime();
void StopTimeAndGetDuration();
bool IsPrime(int number);
SearchRangeStruct *CreateSearchRanges(int *ranges, int threadCount);
void *ParallelFindPrimes(void *args);
void CreateThreads(pthread_t *channels, int threadCount, SearchRangeStruct *searchRanges);
void JoinThreads(pthread_t *channels, int threadCount);
void WriteOutput(int number);

bool IsPrime(int number)
{
    if (number < 2)
        return false;
    int i = 2;
    int limit = number / 2;
    while (i < limit)
    {
        if (number % i == 0)
            return false;
        i++;
    }
    return true;
}

SearchRangeStruct *CreateSearchRanges(int *ranges, int threadCount)
{
    SearchRangeStruct *searchRanges = (SearchRangeStruct *)malloc(threadCount * sizeof(SearchRangeStruct *));
    searchRanges[0].start = ranges[0];
    searchRanges[0].end = ranges[0] + ((ranges[1] - ranges[0]) / threadCount);

    for (int i = 1; i < threadCount; i++)
    {
        searchRanges[i].start = searchRanges[i - 1].end + 1;
        searchRanges[i].end = searchRanges[i].start + ((searchRanges[0].end - searchRanges[0].start) - 1);
    }

    return searchRanges;
}

void *ParallelFindPrimes(void *args)
{
    SearchRangeStruct *searchRange = (SearchRangeStruct *)args;
    for (int i = searchRange->start; i <= searchRange->end; i++)
        if (IsPrime(i))
            WriteOutput(i);

    return NULL;
}

void CreateThreads(pthread_t *channels, int threadCount, SearchRangeStruct *searchRanges)
{
    for (int i = 0; i < threadCount; i++)
        pthread_create(&channels[i], NULL, ParallelFindPrimes, &searchRanges[i]);
}

void JoinThreads(pthread_t *channels, int threadCount)
{
    for (int i = 0; i < threadCount; i++)
        pthread_join(channels[i], NULL);
}

void WriteOutput(int number)
{
    cout << " " << number << " " << endl;
}

void StartTime()
{
    startTime = chrono::high_resolution_clock::now();
}

void StopTimeAndGetDuration()
{
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    cout << endl
         << "Duration: " << duration.count() << " milliseconds" << endl;
}

#endif
