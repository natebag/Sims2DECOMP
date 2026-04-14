// 0x800EB2CC cXObjectImpl::GetDef (8B)

struct cXObj_GetDef {
    char pad[0x88];
    int m_val;
    int GetDef();
};

int cXObj_GetDef::GetDef() {
    return m_val;
}
