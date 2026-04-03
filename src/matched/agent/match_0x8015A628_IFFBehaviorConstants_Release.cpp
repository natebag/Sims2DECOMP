/* IFFBehaviorConstants::Release(void) - 0x8015A628 - 92 bytes */

struct IFFBehaviorConstants {
    char _pad[0x60];
    int m_refCount;

    int Release();
};

int IFFBehaviorConstants::Release() {
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
