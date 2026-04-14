/* IFFSlotDescList::Release(void) - 0x80145028 - 92 bytes */

struct IFFSlotDescList {
    char _pad[100];
    int m_refCount;

    int Release();
};

int IFFSlotDescList::Release() {
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
