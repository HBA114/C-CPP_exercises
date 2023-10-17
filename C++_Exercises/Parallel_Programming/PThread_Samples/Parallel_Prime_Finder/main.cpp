#include "findPrimes.h"

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

    StartTime();

    pthread_t *channels = (pthread_t *)malloc(threadCount * sizeof(pthread_t *));

    SearchRangeStruct *searchRanges = CreateSearchRanges(range, threadCount);

    CreateThreads(channels, threadCount, searchRanges);

    JoinThreads(channels, threadCount);

    StopTimeAndGetDuration();

    return 0;
}
