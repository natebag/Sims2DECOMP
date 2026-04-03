/* IFFBehavior::IFFBehavior(void) - 0x800ACC24 - 68 bytes */

struct Behavior {
    char _data[16];
    Behavior();
};

struct IFFBehavior : public Behavior {
    int m_refCount;
    IFFBehavior();
};

extern void *__vt__IFFBehavior[];

IFFBehavior::IFFBehavior() : Behavior() {
    m_refCount = 0;
    *(void ***)this = __vt__IFFBehavior;
}
