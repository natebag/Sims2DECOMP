// 0x802D84FC EThread::IsCallingThread(void) (60B)
//
// Calls GetCurrentThreadId, compares result with m_thread_id field at +792.
// Recipe: 1 swap_operands for xor commutative operands.
//
// ASMPROC_swap_operands: match="xor 3,3,0" pos=1,2

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
    return (cur == my) ? 1 : 0;
}
}
