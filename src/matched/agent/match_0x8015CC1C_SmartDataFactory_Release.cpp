/* SmartDataFactory::Release(void) - 0x8015CC1C - 92 bytes */

struct SmartDataFactory {
    char _pad[20];
    int m_refCount;

    int Release();
};

int SmartDataFactory::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            int *vtable = *(int **)this;
            short delta = *(short *)((char *)vtable + 56);
            void (*func)(void *, int) = (void (*)(void *, int))vtable[15];
            func((char *)this + delta, 3);
        }
        return 0;
    }
    return count;
}
