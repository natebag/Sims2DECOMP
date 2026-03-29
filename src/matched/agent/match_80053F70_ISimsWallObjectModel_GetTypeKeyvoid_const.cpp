// 0x80053F70 (12 bytes) - ISimsWallObjectModel::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80053F70 { int data[4]; };
extern TI_80053F70 g_80053F70;

struct C_80053F70 {
    int fn() const;
};

int C_80053F70::fn() const {
    return g_80053F70.data[3];
}
