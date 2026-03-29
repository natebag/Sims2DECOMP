/* ObjectDataFactoryQuickData<ObjFnTable>::operator()(void) const at 0x8015BA5C (32B) */

extern void* QuickDataObjFnTableLoad(void*);

struct ObjectDataFactoryQuickData_ObjFnTable {
    void* call() const;
};

void* ObjectDataFactoryQuickData_ObjFnTable::call() const {
    return QuickDataObjFnTableLoad((void*)this);
}
