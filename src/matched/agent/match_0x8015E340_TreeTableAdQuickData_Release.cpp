/* TreeTableAdQuickData::Release(void) - 0x8015E340 - 92 bytes */

struct TreeTableAdQuickData {
    char _pad[8];
    int m_refCount;

    int Release();
};

int TreeTableAdQuickData::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            int *vtable = *(int **)this;
            short delta = *(short *)((char *)vtable + 104);
            void (*func)(void *, int) = (void (*)(void *, int))vtable[27];
            func((char *)this + delta, 3);
        }
        return 0;
    }
    return count;
}
