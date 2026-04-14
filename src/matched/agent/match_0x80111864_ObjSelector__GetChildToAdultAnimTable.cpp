// 0x80111864 ObjSelector::GetChildToAdultAnimTable (96B)

struct AnimTableProviderVtbl {
    char pad[0x10];
    short adj;
    void* func;
};

struct AnimTableProvider {
    AnimTableProviderVtbl* vtable;
};

extern AnimTableProvider* ObjSelector_InitAnimTable(void* self);

struct ObjSelector {
    AnimTableProvider* GetChildToAdultAnimTable();
};

AnimTableProvider* ObjSelector::GetChildToAdultAnimTable() {
    if (*(AnimTableProvider**)((char*)this + 0x4c) == 0) {
        AnimTableProvider* table = ObjSelector_InitAnimTable(this);
        *(AnimTableProvider**)((char*)this + 0x4c) = table;
        AnimTableProviderVtbl* vt = table->vtable;
        ((void (*)(void*, void*, int))vt->func)((char*)table + vt->adj, *(void**)((char*)this + 4), 0x84);
    }
    return *(AnimTableProvider**)((char*)this + 0x4c);
}
