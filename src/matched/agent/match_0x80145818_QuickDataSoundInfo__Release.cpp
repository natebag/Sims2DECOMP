struct QuickDataSoundInfo {
    char _pad[0x58];
    int m_refCount;

    int Release();
};

void operator delete(void *);

int QuickDataSoundInfo::Release() {
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
