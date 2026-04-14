// 0x8012C7F4 cXPersonImpl::GetCurrentRoom (8B)

struct cXPerson_GCR {
    char pad[0x41C];
    unsigned short m_val;
    unsigned short GetCurrentRoom() const;
};

unsigned short cXPerson_GCR::GetCurrentRoom() const {
    return m_val;
}
