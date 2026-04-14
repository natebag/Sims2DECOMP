/* IFFBehavior::Release(void) - 0x800AD034 - 92 bytes */

struct IFFBehavior {
    char _pad[16];
    int m_refCount;

    int Release();
};

int IFFBehavior::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            int *vtable = *(int **)this;
            short delta = *(short *)((char *)vtable + 32);
            void (*func)(void *, int) = (void (*)(void *, int))vtable[9];
            func((char *)this + delta, 3);
        }
        return 0;
    }
    return count;
}
