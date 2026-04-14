/* IFFBehaviorTree::Release(void) - 0x8015B89C - 92 bytes */

struct IFFBehaviorTree {
    char _pad[96];
    int m_refCount;

    int Release();
};

int IFFBehaviorTree::Release() {
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
