// 0x80053F64 (12 bytes) - ISimsWallObjectModel::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80053F64 { int data[4]; };
extern TI_80053F64 g_80053F64;

struct C_80053F64 {
    int fn() const;
};

int C_80053F64::fn() const {
    return g_80053F64.data[3];
}
