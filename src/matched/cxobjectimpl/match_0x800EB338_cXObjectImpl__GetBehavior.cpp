// 0x800EB338 cXObjectImpl::GetBehavior (12B)

struct Inner_GetBehavior {
    char pad[0xC];
    int m_val;
};

struct cXObj_GetBehavior {
    char pad[0x8C];
    Inner_GetBehavior* m_inner;
    int GetBehavior();
};

int cXObj_GetBehavior::GetBehavior() {
    return m_inner->m_val;
}
