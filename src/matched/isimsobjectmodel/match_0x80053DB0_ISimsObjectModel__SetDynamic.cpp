// 0x80053DB0 (40B) ISimsObjectModel::SetDynamic(bool)
// Sets or clears bit 0x40 at offset +0x32C based on bool parameter.

struct ISimsObjectModel {
    char _pad[0x32C];
    unsigned int m_flags;
    void SetDynamic(bool dynamic);
};

void ISimsObjectModel::SetDynamic(bool dynamic) {
    if (dynamic) {
        m_flags |= 0x40;
    } else {
        m_flags &= ~0x40;
    }
}
