// 0x80053CEC (12 bytes) - ISimsObjectModel::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80053CEC { int data[4]; };
extern TI_80053CEC g_80053CEC;

struct C_80053CEC {
    int fn() const;
};

int C_80053CEC::fn() const {
    return g_80053CEC.data[3];
}
