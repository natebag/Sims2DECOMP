// 0x8022A59C (12 bytes) - EIPointLight::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022A59C { int data[4]; };
extern TI_8022A59C g_8022A59C;

struct C_8022A59C {
    unsigned short fn() const;
};

unsigned short C_8022A59C::fn() const {
    return *(unsigned short*)&g_8022A59C.data[3];
}
