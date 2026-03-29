// 0x80048404 (12 bytes) - EIFloor::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80048404 { int data[4]; };
extern TI_80048404 g_80048404;

struct C_80048404 {
    int fn() const;
};

int C_80048404::fn() const {
    return g_80048404.data[3];
}
