// 0x800EB330 cXObjectImpl::GetSelector (8B) const

struct cXObj_GSc {
    char pad[0x8C];
    int m_val;
    int GetSelectorC() const;
};

int cXObj_GSc::GetSelectorC() const {
    return m_val;
}
