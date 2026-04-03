/* TreeTableEntryQuickData::Release(void) - 0x8015E420 - 92 bytes */

struct TreeTableEntryQuickData {
    char _pad[24];
    int m_refCount;

    int Release();
};

int TreeTableEntryQuickData::Release() {
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
