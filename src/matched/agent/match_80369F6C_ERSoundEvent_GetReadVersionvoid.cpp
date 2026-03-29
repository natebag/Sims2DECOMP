// 0x80369F6C (12 bytes) - ERSoundEvent::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80369F6C { int data[4]; };
extern TI_80369F6C g_80369F6C;

struct C_80369F6C {
    unsigned short fn() const;
};

unsigned short C_80369F6C::fn() const {
    return *(unsigned short*)&g_80369F6C.data[3];
}
