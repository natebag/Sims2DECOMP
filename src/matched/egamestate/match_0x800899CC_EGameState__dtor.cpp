extern int EGameState_vtable[];

struct EAHeap {
    void Free(void *p);
};

extern EAHeap *MainHeap(void);

struct EGameState {
    char pad[8];
    int *m_vtable;  // offset 0x08
    void dtor_fn(int flags);
};

void EGameState::dtor_fn(int flags) {
    m_vtable = (int *)EGameState_vtable;
    if (flags & 1) {
        EAHeap *heap = MainHeap();
        heap->Free(this);
    }
}
