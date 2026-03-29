// 0x80053D1C (12 bytes) - ISimsObjectModel::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80053D1C { int data[4]; };
extern TI_80053D1C g_80053D1C;

struct C_80053D1C {
    unsigned short fn() const;
};

unsigned short C_80053D1C::fn() const {
    return *(unsigned short*)&g_80053D1C.data[3];
}
