// 0x8012C988 cXPersonImpl::GetMotiveEffects (8B)

struct cXPerson_GetMotiveEffects {
    char pad[0x408];
    int m_val;
    int GetMotiveEffects();
};

int cXPerson_GetMotiveEffects::GetMotiveEffects() {
    return m_val;
}
