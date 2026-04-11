// EEngine::FrameComplete(void)
// 0x802E31FC | 60 bytes
// Calls _pSched->QueueCompletionEvent(this->m_semaphore)
// _pSched vtable ptr at offset 0x338, QueueCompletionEvent at vtable entry 7 (offset 0x38)

struct EEvent;

// Scheduler base class whose vtable is at offset 0x338 of ENgcScheduler
// ENgcScheduler stores its vtable at m_field_338 (offset 0x338)
// The vtable has QueueCompletionEvent at entry 7 (offset 0x38)
struct ESchedulerBase {
    virtual ~ESchedulerBase();
    virtual void Main();
    virtual void Init();
    virtual void QueueSetupFrameBuffer(int);
    virtual void QueueDisplayList(void*, bool);
    virtual void QueueSwapBuffer(int, int);
    virtual void QueueFlush();
    virtual void QueueCompletionEvent(EEvent&);  // entry 7, offset 0x38
};

// ENgcScheduler object has EThread-like base at start, and ESchedulerBase at offset 0x338
struct ENgcSchedulerLayout {
    char _pad[0x338];
    ESchedulerBase m_sched;  // vtable ptr for ENgcScheduler virtual methods
};

class ESemaphore;  // EEngine's semaphore at offset 0x34

class EEngine {
public:
    char _pad[0x34];
    EEvent* m_completionEvent;  // treated as EEvent at offset 0x34
    void FrameComplete();
};

extern ENgcSchedulerLayout* _pSched;

void EEngine::FrameComplete() {
    _pSched->m_sched.QueueCompletionEvent(*(EEvent*)((char*)this + 52));
}
