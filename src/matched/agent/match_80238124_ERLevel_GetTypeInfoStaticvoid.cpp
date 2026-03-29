// 0x80238124 (12 bytes) - ERLevel::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80238124 { int data[4]; };
extern TI_80238124 g_80238124;

TI_80238124* fn_80238124() {
    return &g_80238124;
}
