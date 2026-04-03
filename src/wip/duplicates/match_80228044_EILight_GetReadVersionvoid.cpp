// 0x80228044 (12 bytes) - EILight::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80228044 { int data[4]; };
extern TI_80228044 g_80228044;

struct C_80228044 {
    unsigned short fn() const;
};

unsigned short C_80228044::fn() const {
    return *(unsigned short*)&g_80228044.data[3];
}
