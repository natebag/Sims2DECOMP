// 0x800EB8D0 cXObjectImpl::GetName (12B) const

struct Inner_GetName {
    char pad[0x14];
    int m_val;
};

struct cXObj_GetName {
    char pad[0x8C];
    Inner_GetName* m_inner;
    int GetName() const;
};

int cXObj_GetName::GetName() const {
    return m_inner->m_val;
}
