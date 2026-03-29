// 0x8022782C (12 bytes) - EIGameInstance::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022782C { int data[4]; };
extern TI_8022782C g_8022782C;

TI_8022782C* fn_8022782C() {
    return &g_8022782C;
}
