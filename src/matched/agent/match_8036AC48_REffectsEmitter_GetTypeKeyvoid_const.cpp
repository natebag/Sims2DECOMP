// 0x8036AC48 (12 bytes) - REffectsEmitter::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036AC48 { int data[4]; };
extern TI_8036AC48 g_8036AC48;

struct C_8036AC48 {
    int fn() const;
};

int C_8036AC48::fn() const {
    return g_8036AC48.data[3];
}
