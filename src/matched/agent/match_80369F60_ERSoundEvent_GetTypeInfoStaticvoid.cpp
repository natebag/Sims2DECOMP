// 0x80369F60 (12 bytes) - ERSoundEvent::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80369F60 { int data[4]; };
extern TI_80369F60 g_80369F60;

TI_80369F60* fn_80369F60() {
    return &g_80369F60;
}
