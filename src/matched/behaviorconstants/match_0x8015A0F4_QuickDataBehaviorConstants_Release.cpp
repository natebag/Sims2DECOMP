/* QuickDataBehaviorConstants::Release(void) - 0x8015A0F4 - 92 bytes */

struct QuickDataBehaviorConstants {
    char _pad[0x1C];
    int m_refCount;

    int Release();
};

int QuickDataBehaviorConstants::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            int *vtable = *(int **)this;
            short delta = *(short *)((char *)vtable + 112);
            void (*func)(void *, int) = (void (*)(void *, int))vtable[29];
            func((char *)this + delta, 3);
        }
        return 0;
    }
    return count;
}
