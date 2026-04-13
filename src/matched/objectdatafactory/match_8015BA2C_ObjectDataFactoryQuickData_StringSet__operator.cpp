// 0x8015BA2C ObjectDataFactoryQuickData<StringSet>::operator() (32b)

extern void* QuickDataStringSetLoad(void*);

struct ObjectDataFactoryQuickData_StringSet {
    void* call() const;
};

void* ObjectDataFactoryQuickData_StringSet::call() const {
    return QuickDataStringSetLoad((void*)this);
}
