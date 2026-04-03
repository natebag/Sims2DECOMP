// 0x80227808 (12 bytes) - EIGameInstance::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80227808 { int data[4]; };
extern TI_80227808 g_80227808;

struct C_80227808 {
    int fn() const;
};

int C_80227808::fn() const {
    return g_80227808.data[3];
}
