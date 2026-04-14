/* TreeTableQuickData::Release(void) - 0x8015E500 - 92 bytes */

struct TreeTableQuickData {
    char _pad[32];
    int m_refCount;

    int Release();
};

int TreeTableQuickData::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            int *vtable = *(int **)this;
            short delta = *(short *)((char *)vtable + 264);
            void (*func)(void *, int) = (void (*)(void *, int))vtable[67];
            func((char *)this + delta, 3);
        }
        return 0;
    }
    return count;
}
