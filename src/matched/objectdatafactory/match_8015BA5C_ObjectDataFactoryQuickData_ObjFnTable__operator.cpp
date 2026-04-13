// 0x8015BA5C ObjectDataFactoryQuickData<ObjFnTable>::operator() (32b)

extern void* QuickDataObjFnTableLoad(void*);

struct ObjectDataFactoryQuickData_ObjFnTable {
    void* call() const;
};

void* ObjectDataFactoryQuickData_ObjFnTable::call() const {
    return QuickDataObjFnTableLoad((void*)this);
}
