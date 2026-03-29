// 0x80238118 (12 bytes) - ERLevel::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80238118 { int data[4]; };
extern TI_80238118 g_80238118;

struct C_80238118 {
    unsigned short fn() const;
};

unsigned short C_80238118::fn() const {
    return *(unsigned short*)&g_80238118.data[3];
}
