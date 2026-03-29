typedef unsigned int uint;
typedef void (*VoidFn)(void*);
typedef void (*DtorFn)(void*, int);

struct AptBooleanBase {
    char pad[8];
    int* m_vtable;
    void* m_next;
};

extern AptBooleanBase* AptBoolean_spFirstFree;

void AptBoolean_ClearPool()
{
    while (AptBoolean_spFirstFree != 0) {
        AptBooleanBase* current = AptBoolean_spFirstFree;
        int* vt = current->m_vtable;
        void* next = current->m_next;
        short delta = *(short*)((char*)vt + 0x60);
        void* fn = *(void**)((char*)vt + 0x64);
        ((VoidFn)fn)((char*)current + delta);

        AptBooleanBase* temp = AptBoolean_spFirstFree;
        if (temp != 0) {
            int* vt2 = temp->m_vtable;
            short delta2 = *(short*)((char*)vt2 + 0x78);
            void* fn2 = *(void**)((char*)vt2 + 0x7C);
            ((DtorFn)fn2)((char*)temp + delta2, 3);
        }
        AptBoolean_spFirstFree = (AptBooleanBase*)next;
    }
}
