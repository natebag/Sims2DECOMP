// 0x80227814 (12 bytes) - EIGameInstance::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80227814 { int data[4]; };
extern TI_80227814 g_80227814;

struct C_80227814 {
    int fn() const;
};

int C_80227814::fn() const {
    return g_80227814.data[3];
}
