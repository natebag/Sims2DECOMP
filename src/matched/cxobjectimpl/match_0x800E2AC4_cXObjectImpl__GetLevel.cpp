// 0x800E2AC4 cXObjectImpl::GetLevel (8B) const

struct cXObj_GL {
    char pad[0x80];
    int m_val;
    int GetLevel() const;
};

int cXObj_GL::GetLevel() const {
    return m_val;
}
