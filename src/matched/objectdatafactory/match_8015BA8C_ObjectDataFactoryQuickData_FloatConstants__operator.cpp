// 0x8015BA8C ObjectDataFactoryQuickData<FloatConstants>::operator() (32b)

extern void* QuickDataFloatConstantsLoad(void*);

struct ObjectDataFactoryQuickData_FloatConstants {
    void* call() const;
};

void* ObjectDataFactoryQuickData_FloatConstants::call() const {
    return QuickDataFloatConstantsLoad((void*)this);
}
