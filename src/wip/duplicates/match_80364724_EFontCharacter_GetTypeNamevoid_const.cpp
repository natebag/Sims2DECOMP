// 0x80364724 (12 bytes) - EFontCharacter::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80364724 { int data[4]; };
extern TI_80364724 g_80364724;

struct C_80364724 {
    int fn() const;
};

int C_80364724::fn() const {
    return g_80364724.data[3];
}
