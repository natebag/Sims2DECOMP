// 0x80053DB0 (40B) ISimsObjectModel::SetDynamic(bool)
// if on: flags |= 0x40; else flags &= ~0x40 at +0x32c

struct ISimsObjectModel_SD {
    char _pad[0x32c];
    unsigned int m_flags;
    void SetDynamic(bool on);
};

void ISimsObjectModel_SD::SetDynamic(bool on) {
    if (on) {
        m_flags |= 0x40;
    } else {
        m_flags &= ~0x40;
    }
}
