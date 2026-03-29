// 0x80369F48 (12 bytes) - ERSoundEvent::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80369F48 { int data[4]; };
extern TI_80369F48 g_80369F48;

struct C_80369F48 {
    int fn() const;
};

int C_80369F48::fn() const {
    return g_80369F48.data[3];
}
