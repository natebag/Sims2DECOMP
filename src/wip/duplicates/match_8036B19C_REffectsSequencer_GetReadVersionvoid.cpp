// 0x8036B19C (12 bytes) - REffectsSequencer::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036B19C { int data[4]; };
extern TI_8036B19C g_8036B19C;

struct C_8036B19C {
    unsigned short fn() const;
};

unsigned short C_8036B19C::fn() const {
    return *(unsigned short*)&g_8036B19C.data[3];
}
