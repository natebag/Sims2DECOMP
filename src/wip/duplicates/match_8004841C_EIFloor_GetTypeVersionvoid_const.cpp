// 0x8004841C (12 bytes) - EIFloor::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8004841C { int data[4]; };
extern TI_8004841C g_8004841C;

struct C_8004841C {
    unsigned short fn() const;
};

unsigned short C_8004841C::fn() const {
    return *(unsigned short*)&g_8004841C.data[3];
}
