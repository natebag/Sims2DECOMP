// 0x80369F3C (12 bytes) - ERSoundEvent::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80369F3C { int data[4]; };
extern TI_80369F3C g_80369F3C;

struct C_80369F3C {
    int fn() const;
};

int C_80369F3C::fn() const {
    return g_80369F3C.data[3];
}
