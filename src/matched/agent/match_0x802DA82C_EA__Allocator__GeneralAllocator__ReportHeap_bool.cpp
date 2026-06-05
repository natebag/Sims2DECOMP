// 0x802DA82C EA::Allocator::GeneralAllocator::ReportHeap(bool (*)(BlockInfo*, void*), void*, int, bool, void*, unsigned int) (184 B)
// Walk every block of a heap report, invoking a user callback per block.
// ReportBegin opens the report (returns a context); ReportNext yields each
// BlockInfo* in turn; the callback decides whether to keep going; ReportEnd
// closes the report. Returns false if no callback was supplied or the report
// could not be opened, otherwise the last callback verdict (true if the heap
// was empty but successfully reported).
namespace EA { namespace Allocator {

struct GeneralAllocator {
    struct BlockInfo;
    typedef bool (*ReportCallback)(BlockInfo*, void*);

    bool       ReportHeap(ReportCallback pCallback, void* pContext, int a3, bool a4, void* a5, unsigned int a6);
    void*      ReportBegin(void* pSnapshot, int a2, bool a3, void* a4, unsigned int a5);
    BlockInfo* ReportNext(void* pReport, int a2);
    void       ReportEnd(void* pReport);
};

bool GeneralAllocator::ReportHeap(ReportCallback pCallback, void* pContext, int a3, bool a4, void* a5, unsigned int a6)
{
    bool result = false;

    if (pCallback != 0) {
        void* pReport = ReportBegin(0, a3, a4, a5, a6);

        if (pReport != 0) {
            result = true;
            BlockInfo* pInfo = ReportNext(pReport, a3);

            if (pInfo != 0) {
                do {
                    result = pCallback(pInfo, pContext);
                    pInfo = ReportNext(pReport, a3);
                } while (result && pInfo != 0);
            }
        }

        ReportEnd(pReport);
    }

    return result;
}

}}
