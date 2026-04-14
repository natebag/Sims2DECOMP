// 0x801117A4 ObjSelector::GetChildAnimTable (96B)

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
    AnimTableProvider* GetChildAnimTable();
};

AnimTableProvider* ObjSelector::GetChildAnimTable() {
    if (*(AnimTableProvider**)((char*)this + 0x44) == 0) {
        AnimTableProvider* table = ObjSelector_InitAnimTable(this);
        *(AnimTableProvider**)((char*)this + 0x44) = table;
        AnimTableProviderVtbl* vt = table->vtable;
        ((void (*)(void*, void*, int))vt->func)((char*)table + vt->adj, *(void**)((char*)this + 4), 0x82);
    }
    return *(AnimTableProvider**)((char*)this + 0x44);
}
