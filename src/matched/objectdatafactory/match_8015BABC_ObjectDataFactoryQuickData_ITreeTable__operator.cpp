// 0x8015BABC ObjectDataFactoryQuickData<ITreeTable>::operator() (40b)

extern void* operator_new(int);
extern void* TreeTableQuickData_ctor(void*);

void* QuickDataITreeTableCreate(void) {
    void* p = operator_new(36);
    return TreeTableQuickData_ctor(p);
}
