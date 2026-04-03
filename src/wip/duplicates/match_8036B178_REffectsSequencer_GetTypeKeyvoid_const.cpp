// 0x8036B178 (12 bytes) - REffectsSequencer::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036B178 { int data[4]; };
extern TI_8036B178 g_8036B178;

struct C_8036B178 {
    int fn() const;
};

int C_8036B178::fn() const {
    return g_8036B178.data[3];
}
