// 0x8036AC6C (12 bytes) - REffectsEmitter::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036AC6C { int data[4]; };
extern TI_8036AC6C g_8036AC6C;

struct C_8036AC6C {
    unsigned short fn() const;
};

unsigned short C_8036AC6C::fn() const {
    return *(unsigned short*)&g_8036AC6C.data[3];
}
