// 0x80141B28 cSimulatorImpl::SetArchValue(int) (48B)
struct cSimulatorImpl {
    char pad[90];
    short m_archCents;      // 90
    short m_archDollars;    // 92
    char pad2[46];
    int m_rawArch;          // 140
};

void cSimulatorImpl__SetArchValue(cSimulatorImpl* self, int value) {
    self->m_rawArch = value;
    self->m_archDollars = value / 10000;
    self->m_archCents = value % 10000;
}
