// 0x80054420 (12 bytes) - IShrubObject::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80054420 { int data[4]; };
extern TI_80054420 g_80054420;

struct C_80054420 {
    int fn() const;
};

int C_80054420::fn() const {
    return g_80054420.data[3];
}
