// 0x8022A584 (12 bytes) - EIPointLight::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022A584 { int data[4]; };
extern TI_8022A584 g_8022A584;

struct C_8022A584 {
    unsigned short fn() const;
};

unsigned short C_8022A584::fn() const {
    return *(unsigned short*)&g_8022A584.data[3];
}
