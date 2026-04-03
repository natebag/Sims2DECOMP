// 0x803680BC (12 bytes) - ERAnim::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_803680BC { int data[4]; };
extern TI_803680BC g_803680BC;

TI_803680BC* fn_803680BC() {
    return &g_803680BC;
}
