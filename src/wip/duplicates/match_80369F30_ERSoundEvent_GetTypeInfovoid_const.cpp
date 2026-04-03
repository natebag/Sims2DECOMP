// 0x80369F30 (12 bytes) - ERSoundEvent::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80369F30 { int data[4]; };
extern TI_80369F30 g_80369F30;

TI_80369F30* fn_80369F30() {
    return &g_80369F30;
}
