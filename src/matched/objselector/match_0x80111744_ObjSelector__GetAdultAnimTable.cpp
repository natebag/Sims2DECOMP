// 0x80111744 ObjSelector::GetAdultAnimTable (96B)

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
    AnimTableProvider* GetAdultAnimTable();
};

AnimTableProvider* ObjSelector::GetAdultAnimTable() {
    if (*(AnimTableProvider**)((char*)this + 0x40) == 0) {
        AnimTableProvider* table = ObjSelector_InitAnimTable(this);
        *(AnimTableProvider**)((char*)this + 0x40) = table;
        AnimTableProviderVtbl* vt = table->vtable;
        ((void (*)(void*, void*, int))vt->func)((char*)table + vt->adj, *(void**)((char*)this + 4), 0x81);
    }
    return *(AnimTableProvider**)((char*)this + 0x40);
}
