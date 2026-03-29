// 0x80227418 (12 bytes) - EIDirLight::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80227418 { int data[4]; };
extern TI_80227418 g_80227418;

TI_80227418* fn_80227418() {
    return &g_80227418;
}
