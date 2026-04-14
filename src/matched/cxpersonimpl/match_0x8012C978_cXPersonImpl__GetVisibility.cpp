// 0x8012C978 cXPersonImpl::GetVisibility (8B)

struct cXPerson_GV {
    char pad[0x9C];
    short m_val;
    short GetVisibility();
};

short cXPerson_GV::GetVisibility() {
    return m_val;
}
