// 0x802DA70C EA::Allocator::GeneralAllocator::TraceAllocatedMemory(void (*)(char*, void*), void*, void*, unsigned int) (288 B)
// Under the allocator mutex, walk every reported chunk and hand a textual
// description of each to a user trace callback. Flushes the fast bins first (if
// enabled), defaults the callback/context to the allocator's stored trace hooks,
// formats each non-skipped chunk into a local buffer via DescribeChunk, and
// fires the callback per chunk.
namespace EA { namespace Allocator {

typedef void (*TraceCallback)(char*, void*);

struct Chunk {
    unsigned int mPrevSize;  // 0x00
    unsigned int mnSize;     // 0x04  size | flag bits
};

extern "C" void PPMMutexLock(void* pMutex);
extern "C" void PPMMutexUnlock(void* pMutex);

struct PPMutexAutoLock {
    void* mpMutex;
    PPMutexAutoLock(void* pMutex) : mpMutex(pMutex) { if (mpMutex) PPMMutexLock(mpMutex); }
    ~PPMutexAutoLock() { if (mpMutex) PPMMutexUnlock(mpMutex); }
};

struct GeneralAllocator {
    char          mPad0[0x04];           // 0x00
    unsigned int  mFlags;                // 0x04
    char          mPad08[0x4D8 - 0x08];  // 0x08
    TraceCallback mDefaultCallback;      // 0x4D8
    void*         mDefaultContext;       // 0x4DC
    char          mPad4E0[0x4F8 - 0x4E0];// 0x4E0
    int           mField4F8;             // 0x4F8
    void*         mpMutex;               // 0x4FC

    void  TraceAllocatedMemory(TraceCallback pCallback, void* pContext, void* a3, unsigned int a4);
    void  ClearFastBins();
    void* ReportBegin(void* pSnapshot, int a2, bool a3, void* a4, unsigned int a5);
    void* ReportNext(void* pReport, int a2);
    void  ReportEnd(void* pReport);
    void  DescribeChunk(Chunk* pChunk, char* pBuffer, unsigned int nSize);
};

void GeneralAllocator::TraceAllocatedMemory(TraceCallback pCallback, void* pContext, void* a3, unsigned int a4)
{
    char buffer[2500];

    PPMutexAutoLock lock(mpMutex);

    if (mFlags & 1)
        ClearFastBins();

    if (pCallback == 0)
        pCallback = mDefaultCallback;
    if (pContext == 0)
        pContext = mDefaultContext;

    if (pCallback != 0) {
        void* pReport = ReportBegin(0, 2, 0, a3, a4);
        void* pInfo = ReportNext(pReport, 15);

        while (pInfo != 0) {
            Chunk* pChunk = *(Chunk**)pInfo;
            if (mField4F8 != 0 || (pChunk->mnSize & 4) == 0) {
                DescribeChunk(pChunk, buffer, 2500);
                pCallback(buffer, pContext);
            }
            pInfo = ReportNext(pReport, 15);
        }

        ReportEnd(pReport);
    }
}

}}
