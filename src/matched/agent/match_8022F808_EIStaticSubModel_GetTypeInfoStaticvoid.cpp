// 0x8022F808 (12 bytes) - EIStaticSubModel::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022F808 { int data[4]; };
extern TI_8022F808 g_8022F808;

TI_8022F808* fn_8022F808() {
    return &g_8022F808;
}
