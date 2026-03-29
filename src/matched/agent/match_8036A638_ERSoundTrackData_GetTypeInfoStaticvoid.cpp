// 0x8036A638 (12 bytes) - ERSoundTrackData::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036A638 { int data[4]; };
extern TI_8036A638 g_8036A638;

TI_8036A638* fn_8036A638() {
    return &g_8036A638;
}
