// StubObject::MakeNewGUID - generates a GUID from time, perf counter, and rand

extern void QueryPerformanceCounter(long long *out);
extern int GetTimeDate(void);
extern int rand(void);

int StubObject_MakeNewGUID(void) {
    long long counter;
    QueryPerformanceCounter(&counter);
    int timedate = GetTimeDate();
    int r = rand();
    int counter_lo = *(((int *)&counter) + 1); // low word at offset 4
    return timedate ^ (counter_lo ^ r);
}
