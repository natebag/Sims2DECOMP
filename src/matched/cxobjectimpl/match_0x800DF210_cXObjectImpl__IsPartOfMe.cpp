// 0x800DF210 cXObjectImpl::IsPartOfMe (20B)

struct cXObj_IPOM {
    char pad_00[4];
    void* m_inner;
    int IsPartOfMe(void* other);
};

int cXObj_IPOM::IsPartOfMe(void* other) {
    return (other == m_inner) ? 1 : 0;
}
