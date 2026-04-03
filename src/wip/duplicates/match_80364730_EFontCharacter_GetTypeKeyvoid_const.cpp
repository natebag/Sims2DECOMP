// 0x80364730 (12 bytes) - EFontCharacter::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80364730 { int data[4]; };
extern TI_80364730 g_80364730;

struct C_80364730 {
    int fn() const;
};

int C_80364730::fn() const {
    return g_80364730.data[3];
}
