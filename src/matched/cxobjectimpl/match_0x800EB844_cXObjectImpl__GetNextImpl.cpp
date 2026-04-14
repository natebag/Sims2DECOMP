// 0x800EB844 cXObjectImpl::GetNextImpl (8B)

struct cXObj_GetNextImpl {
    char pad[0x5C];
    int m_val;
    int GetNextImpl();
};

int cXObj_GetNextImpl::GetNextImpl() {
    return m_val;
}
