// 0x80367230 (12 bytes) - ERAmbientScore::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80367230 { int data[4]; };
extern TI_80367230 g_80367230;

struct C_80367230 {
    int fn() const;
};

int C_80367230::fn() const {
    return g_80367230.data[3];
}
