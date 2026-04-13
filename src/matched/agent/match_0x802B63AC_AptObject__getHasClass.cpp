// 0x802B63AC AptObject::getHasClass (12b)

struct AptObject {
    char _pad[32];
    unsigned int m_flags;
};

int AptObject__getHasClass(AptObject *self) {
    return (self->m_flags >> 23) & 1;
}
