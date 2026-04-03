/* ObjectDataObjDefinition::Release(void) - 0x8015C78C - 92 bytes */

struct ObjectDataObjDefinition {
    char _pad[20];
    int m_refCount;

    int Release();
};

int ObjectDataObjDefinition::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            int *vtable = *(int **)this;
            short delta = *(short *)((char *)vtable + 88);
            void (*func)(void *, int) = (void (*)(void *, int))vtable[23];
            func((char *)this + delta, 3);
        }
        return 0;
    }
    return count;
}
