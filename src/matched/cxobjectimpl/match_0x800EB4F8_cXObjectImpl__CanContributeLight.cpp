// 0x800EB4F8 cXObjectImpl::CanContributeLight (48B)

struct EdithVariableSet {
    unsigned short* operator[](int index);
};

struct cXObj_CanContributeLight {
    char pad[0x28];
    EdithVariableSet m_vars;
    int CanContributeLight();
};

int cXObj_CanContributeLight::CanContributeLight() {
    unsigned short val = *m_vars[40];
    return (val >> 10) & 1;
}
