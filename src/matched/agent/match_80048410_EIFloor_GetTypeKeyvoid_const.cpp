// 0x80048410 (12 bytes) - EIFloor::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80048410 { int data[4]; };
extern TI_80048410 g_80048410;

struct C_80048410 {
    int fn() const;
};

int C_80048410::fn() const {
    return g_80048410.data[3];
}
