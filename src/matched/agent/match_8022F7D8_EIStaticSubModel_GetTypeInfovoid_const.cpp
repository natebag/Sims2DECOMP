// 0x8022F7D8 (12 bytes) - EIStaticSubModel::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022F7D8 { int data[4]; };
extern TI_8022F7D8 g_8022F7D8;

TI_8022F7D8* fn_8022F7D8() {
    return &g_8022F7D8;
}
