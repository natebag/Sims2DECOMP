// 0x80227454 (12 bytes) - EIDirLight::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80227454 { int data[4]; };
extern TI_80227454 g_80227454;

struct C_80227454 {
    unsigned short fn() const;
};

unsigned short C_80227454::fn() const {
    return *(unsigned short*)&g_80227454.data[3];
}
