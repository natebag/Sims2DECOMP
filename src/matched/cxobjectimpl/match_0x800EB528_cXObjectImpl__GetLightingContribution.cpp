// 0x800EB528 cXObjectImpl::GetLightingContribution (44B)

struct EdithVariableSet {
    short* operator[](int index);
};

struct cXObj_GetLightingContribution {
    char pad[0x28];
    EdithVariableSet m_vars;
    short GetLightingContribution();
};

short cXObj_GetLightingContribution::GetLightingContribution() {
    return *m_vars[51];
}
