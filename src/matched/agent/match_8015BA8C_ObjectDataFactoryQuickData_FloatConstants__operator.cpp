/* ObjectDataFactoryQuickData<FloatConstants>::operator()(void) const at 0x8015BA8C (32B) */

extern void* QuickDataFloatConstantsLoad(void*);

struct ObjectDataFactoryQuickData_FloatConstants {
    void* call() const;
};

void* ObjectDataFactoryQuickData_FloatConstants::call() const {
    return QuickDataFloatConstantsLoad((void*)this);
}
