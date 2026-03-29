// 0x80367254 (12 bytes) - ERAmbientScore::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80367254 { int data[4]; };
extern TI_80367254 g_80367254;

TI_80367254* fn_80367254() {
    return &g_80367254;
}
