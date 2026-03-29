/* ObjectDataFactoryQuickData<ITreeTable>::operator()(void) const at 0x8015BABC (40B) */

extern void* operator_new(int);
extern void* TreeTableQuickData_ctor(void*);

void* QuickDataITreeTableCreate(void) {
    void* p = operator_new(36);
    return TreeTableQuickData_ctor(p);
}
