// 0x800EB2E0 cXObjectImpl::GetID (8B)

struct cXObj_GID {
    char pad[0x64];
    short m_val;
    short GetID();
};

short cXObj_GID::GetID() {
    return m_val;
}
