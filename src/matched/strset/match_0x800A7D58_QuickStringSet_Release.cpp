/* QuickStringSet::Release(void) - 0x800A7D58 - 92 bytes */

struct QuickStringSet {
    char _pad[16];
    int m_refCount;

    int Release();
};

int QuickStringSet::Release() {
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
