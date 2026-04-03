// 0x80053F7C (12 bytes) - ISimsWallObjectModel::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80053F7C { int data[4]; };
extern TI_80053F7C g_80053F7C;

struct C_80053F7C {
    unsigned short fn() const;
};

unsigned short C_80053F7C::fn() const {
    return *(unsigned short*)&g_80053F7C.data[3];
}
