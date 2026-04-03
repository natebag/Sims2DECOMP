/* FloatConstantsQuickData::Release(void) - 0x800B7190 - 92 bytes */

struct FloatConstantsQuickData {
    char _pad[16];
    int m_refCount;

    int Release();
};

int FloatConstantsQuickData::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            int *vtable = *(int **)this;
            short delta = *(short *)((char *)vtable + 96);
            void (*func)(void *, int) = (void (*)(void *, int))vtable[25];
            func((char *)this + delta, 3);
        }
        return 0;
    }
    return count;
}
