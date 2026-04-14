// 0x80111804 ObjSelector::GetAdultToChildAnimTable (96B)

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
    AnimTableProvider* GetAdultToChildAnimTable();
};

AnimTableProvider* ObjSelector::GetAdultToChildAnimTable() {
    if (*(AnimTableProvider**)((char*)this + 0x48) == 0) {
        AnimTableProvider* table = ObjSelector_InitAnimTable(this);
        *(AnimTableProvider**)((char*)this + 0x48) = table;
        AnimTableProviderVtbl* vt = table->vtable;
        ((void (*)(void*, void*, int))vt->func)((char*)table + vt->adj, *(void**)((char*)this + 4), 0x83);
    }
    return *(AnimTableProvider**)((char*)this + 0x48);
}
