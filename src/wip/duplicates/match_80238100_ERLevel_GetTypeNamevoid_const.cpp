// 0x80238100 (12 bytes) - ERLevel::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80238100 { int data[4]; };
extern TI_80238100 g_80238100;

struct C_80238100 {
    int fn() const;
};

int C_80238100::fn() const {
    return g_80238100.data[3];
}
