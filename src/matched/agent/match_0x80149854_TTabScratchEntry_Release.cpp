/* TTabScratchEntry::Release(void) - 0x80149854 - 92 bytes */

struct TTabScratchEntry {
    char _pad[280];
    int m_refCount;

    int Release();
};

int TTabScratchEntry::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            int *vtable = *(int **)this;
            short delta = *(short *)((char *)vtable + 488);
            void (*func)(void *, int) = (void (*)(void *, int))vtable[123];
            func((char *)this + delta, 3);
        }
        return 0;
    }
    return count;
}
