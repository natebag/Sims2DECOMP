// 0x8036723C (12 bytes) - ERAmbientScore::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036723C { int data[4]; };
extern TI_8036723C g_8036723C;

struct C_8036723C {
    int fn() const;
};

int C_8036723C::fn() const {
    return g_8036723C.data[3];
}
