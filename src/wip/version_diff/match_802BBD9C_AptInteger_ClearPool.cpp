typedef unsigned int uint;
typedef void (*VoidFn)(void*);
typedef void (*DtorFn)(void*, int);

struct AptIntegerBase {
    char pad[8];
    int* m_vtable;
    void* m_next;
};

extern AptIntegerBase* AptInteger_spFirstFree;

void AptInteger_ClearPool()
{
    while (AptInteger_spFirstFree != 0) {
        AptIntegerBase* current = AptInteger_spFirstFree;
        int* vt = current->m_vtable;
        void* next = current->m_next;
        short delta = *(short*)((char*)vt + 0x60);
        void* fn = *(void**)((char*)vt + 0x64);
        ((VoidFn)fn)((char*)current + delta);

        AptIntegerBase* temp = AptInteger_spFirstFree;
        if (temp != 0) {
            int* vt2 = temp->m_vtable;
            short delta2 = *(short*)((char*)vt2 + 0x78);
            void* fn2 = *(void**)((char*)vt2 + 0x7C);
            ((DtorFn)fn2)((char*)temp + delta2, 3);
        }
        AptInteger_spFirstFree = (AptIntegerBase*)next;
    }
}
