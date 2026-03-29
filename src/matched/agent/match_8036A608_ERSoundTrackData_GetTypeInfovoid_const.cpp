// 0x8036A608 (12 bytes) - ERSoundTrackData::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036A608 { int data[4]; };
extern TI_8036A608 g_8036A608;

TI_8036A608* fn_8036A608() {
    return &g_8036A608;
}
