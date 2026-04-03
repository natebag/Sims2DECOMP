// 0x80368568 (12 bytes) - ERBinary::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80368568 { int data[4]; };
extern TI_80368568 g_80368568;

struct C_80368568 {
    int fn() const;
};

int C_80368568::fn() const {
    return g_80368568.data[3];
}
