// 0x803C9818 (12 bytes) - EAnimNodeDataPos::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_803C9818 { int data[4]; };
extern TI_803C9818 g_803C9818;

struct C_803C9818 {
    int fn() const;
};

int C_803C9818::fn() const {
    return g_803C9818.data[3];
}
