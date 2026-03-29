// 0x80053CF8 (12 bytes) - ISimsObjectModel::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80053CF8 { int data[4]; };
extern TI_80053CF8 g_80053CF8;

struct C_80053CF8 {
    int fn() const;
};

int C_80053CF8::fn() const {
    return g_80053CF8.data[3];
}
