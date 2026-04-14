// 0x800EB328 cXObjectImpl::GetSelector (8B)

struct cXObj_GetSelector {
    char pad[0x8C];
    int m_val;
    int GetSelector();
};

int cXObj_GetSelector::GetSelector() {
    return m_val;
}
