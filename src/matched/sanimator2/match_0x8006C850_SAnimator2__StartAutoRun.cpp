// 0x8006C850 SAnimator2::StartAutoRun(float) (112B)
// Pattern: subobject Awareness check + Tech #56 MI-vcall via p+4 secondary vtable.
// AwarenessAutoRunCheck on (this+1568, speed); if result==1, dispatches via inner-obj's
// secondary vtable at slot 488/492 with args (this-adjusted, 17, 1).

typedef void (*AutoRunFn)(void* adjThis, int a, int b);

class AwarenessManager {
public:
    int AwarenessAutoRunCheck(float speed);
};

class SAnimator2 {
public:
    char pad_0[4];
    void** m_handle;        // offset 4 — ptr-to-ptr to inner obj
    char pad_8[1528];
    int m_field_600;        // offset 1536 (0x600)
    char pad_1540[28];
    AwarenessManager m_awareness;   // offset 1568 (0x620)

    int StartAutoRun(float speed);
};

int SAnimator2::StartAutoRun(float speed) {
    AwarenessManager* am = (AwarenessManager*)((char*)this + 1568);
    int result = am->AwarenessAutoRunCheck(speed);
    m_field_600 = result;
    if (result == 1) {
        char* p = (char*)*m_handle;
        char* secVt = *(char**)(p + 4);
        short adj = *(short*)(secVt + 488);
        AutoRunFn fn = *(AutoRunFn*)(secVt + 492);
        fn(p + adj, 17, 1);
        return 1;
    }
    return 0;
}
