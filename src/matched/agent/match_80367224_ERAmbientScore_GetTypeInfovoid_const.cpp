// 0x80367224 (12 bytes) - ERAmbientScore::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80367224 { int data[4]; };
extern TI_80367224 g_80367224;

TI_80367224* fn_80367224() {
    return &g_80367224;
}
