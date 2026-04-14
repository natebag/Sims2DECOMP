// 0x800EB2D4 cXObjectImpl::GetType (12B)

struct Inner_GetType {
    char pad[0x12];
    short m_val;
};

struct cXObj_GetType {
    char pad[0x88];
    Inner_GetType* m_inner;
    short GetType();
};

short cXObj_GetType::GetType() {
    return m_inner->m_val;
}
