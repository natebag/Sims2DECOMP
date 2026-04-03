// 0x80053F94 (12 bytes) - ISimsWallObjectModel::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80053F94 { int data[4]; };
extern TI_80053F94 g_80053F94;

struct C_80053F94 {
    unsigned short fn() const;
};

unsigned short C_80053F94::fn() const {
    return *(unsigned short*)&g_80053F94.data[3];
}
