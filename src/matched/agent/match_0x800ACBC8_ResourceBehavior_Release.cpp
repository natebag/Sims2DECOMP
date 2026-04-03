/* ResourceBehavior::Release(void) - 0x800ACBC8 - 92 bytes */

struct ResourceBehavior {
    char _pad[28];
    int m_refCount;

    int Release();
};

int ResourceBehavior::Release() {
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
