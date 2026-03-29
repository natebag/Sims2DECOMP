// 0x803680C8 (12 bytes) - ERAnim::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_803680C8 { int data[4]; };
extern TI_803680C8 g_803680C8;

struct C_803680C8 {
    unsigned short fn() const;
};

unsigned short C_803680C8::fn() const {
    return *(unsigned short*)&g_803680C8.data[3];
}
