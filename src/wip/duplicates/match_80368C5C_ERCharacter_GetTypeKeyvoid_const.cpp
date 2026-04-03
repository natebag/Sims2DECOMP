// 0x80368C5C (12 bytes) - ERCharacter::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80368C5C { int data[4]; };
extern TI_80368C5C g_80368C5C;

struct C_80368C5C {
    int fn() const;
};

int C_80368C5C::fn() const {
    return g_80368C5C.data[3];
}
