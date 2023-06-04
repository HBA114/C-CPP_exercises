#include <iostream>
#include <chrono>
#include <pthread.h>

using namespace std;

typedef struct SearchRangeStruct
{
    int start;
    int end;
} searchRangeStruct;

bool isPrime(int number);
SearchRangeStruct *createSearchRanges(int *ranges, int threadCount);

void *parallelFindPrimes(void *args);

void createThreads(pthread_t *channels, int threadCount, SearchRangeStruct *searchRanges);
void joinThreads(pthread_t *channels, int threadCount);

void writeOutput(int number);

int main()
{
    int range[2] = {0, 0};
    int threadCount;
    cout << "Enter start ..." << endl;
    cin >> range[0];
    cout << "Enter end ..." << endl;
    cin >> range[1];
    cout << "Enter thread count ..." << endl;
    cin >> threadCount;

    auto start = chrono::high_resolution_clock::now();

    pthread_t *channels = (pthread_t *)malloc(threadCount * sizeof(pthread_t *));

    SearchRangeStruct *searchRanges = createSearchRanges(range, threadCount);

    createThreads(channels, threadCount, searchRanges);

    joinThreads(channels, threadCount);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << endl
         << "Duration: " << duration.count() << " milliseconds" << endl;

    return 0;
}

bool isPrime(int number)
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

SearchRangeStruct *createSearchRanges(int *ranges, int threadCount)
{
    searchRangeStruct *searchRanges = (searchRangeStruct *)malloc(threadCount * sizeof(searchRangeStruct *));
    searchRanges[0].start = ranges[0];
    searchRanges[0].end = ranges[0] + ((ranges[1] - ranges[0]) / threadCount);

    for (int i = 1; i < threadCount; i++)
    {
        searchRanges[i].start = searchRanges[i - 1].end + 1;
        searchRanges[i].end = searchRanges[i].start + ((searchRanges[0].end - searchRanges[0].start) - 1);
    }

    return searchRanges;
}

void *parallelFindPrimes(void *args)
{
    SearchRangeStruct *searchRange = (SearchRangeStruct *)args;
    for (int i = searchRange->start; i <= searchRange->end; i++)
        if (isPrime(i))
            writeOutput(i);

    return NULL;
}

void createThreads(pthread_t *channels, int threadCount, SearchRangeStruct *searchRanges)
{
    for (int i = 0; i < threadCount; i++)
        pthread_create(&channels[i], NULL, parallelFindPrimes, &searchRanges[i]);
}

void joinThreads(pthread_t *channels, int threadCount)
{
    for (int i = 0; i < threadCount; i++)
        pthread_join(channels[i], NULL);
}

void writeOutput(int number)
{
    cout << " " << number << " " << endl;
}
