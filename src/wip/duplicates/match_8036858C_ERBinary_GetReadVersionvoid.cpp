// 0x8036858C (12 bytes) - ERBinary::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036858C { int data[4]; };
extern TI_8036858C g_8036858C;

struct C_8036858C {
    unsigned short fn() const;
};

unsigned short C_8036858C::fn() const {
    return *(unsigned short*)&g_8036858C.data[3];
}
