// 0x80053D04 (12 bytes) - ISimsObjectModel::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80053D04 { int data[4]; };
extern TI_80053D04 g_80053D04;

struct C_80053D04 {
    unsigned short fn() const;
};

unsigned short C_80053D04::fn() const {
    return *(unsigned short*)&g_80053D04.data[3];
}
