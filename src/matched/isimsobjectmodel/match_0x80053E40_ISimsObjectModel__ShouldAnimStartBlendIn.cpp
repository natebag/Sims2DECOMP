// ISimsObjectModel::ShouldAnimStartBlendIn(unsigned int) at 0x80053E40 (32 bytes)
// Returns true iff m_field at 0x428 is non-zero AND argument is non-zero.

struct ISimsObjectModel_SASB {
    char _pad[0x428];
    int m_animField;     // 1064 = 0x428
    bool ShouldAnimStartBlendIn(unsigned int x);
};

bool ISimsObjectModel_SASB::ShouldAnimStartBlendIn(unsigned int x) {
    return m_animField != 0 && x != 0;
}
