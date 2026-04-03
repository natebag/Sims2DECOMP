/* TreeTableAdScratch::Release(void) - 0x80149774 - 92 bytes */

struct TreeTableAdScratch {
    char _pad[12];
    int m_refCount;

    int Release();
};

int TreeTableAdScratch::Release() {
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
