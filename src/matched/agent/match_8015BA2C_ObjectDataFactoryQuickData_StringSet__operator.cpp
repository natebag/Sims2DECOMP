/* ObjectDataFactoryQuickData<StringSet>::operator()(void) const at 0x8015BA2C (32B) */

extern void* QuickDataStringSetLoad(void*);

struct ObjectDataFactoryQuickData_StringSet {
    void* call() const;
};

void* ObjectDataFactoryQuickData_StringSet::call() const {
    return QuickDataStringSetLoad((void*)this);
}
