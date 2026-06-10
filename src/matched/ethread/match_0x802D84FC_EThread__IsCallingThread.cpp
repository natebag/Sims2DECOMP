// 0x802D84FC EThread::IsCallingThread(void) (60B)
//
// Calls GetCurrentThreadId, compares result with m_thread_id field at +792.
// Recipe: 1 swap_operands for xor commutative operands.
//

namespace EThread {
extern "C" int GetCurrentThreadId();
class EThread {
public:
    int IsCallingThread();
};
}

namespace EThread {
int EThread::IsCallingThread() {
    int cur = GetCurrentThreadId();
    int my = *(int*)((char*)this + 792);
    return (my == cur) ? 1 : 0;
}
}
