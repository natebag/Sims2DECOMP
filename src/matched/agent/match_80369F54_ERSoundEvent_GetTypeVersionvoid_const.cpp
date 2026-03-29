// 0x80369F54 (12 bytes) - ERSoundEvent::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80369F54 { int data[4]; };
extern TI_80369F54 g_80369F54;

struct C_80369F54 {
    unsigned short fn() const;
};

unsigned short C_80369F54::fn() const {
    return *(unsigned short*)&g_80369F54.data[3];
}
