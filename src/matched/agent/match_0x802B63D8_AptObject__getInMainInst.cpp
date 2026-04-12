// 0x802B63D8 AptObject::getInMainInst (12b)

struct AptObject {
    char _pad[32];
    unsigned int m_flags;
};

int AptObject__getInMainInst(AptObject *self) {
    return (self->m_flags >> 22) & 1;
}
