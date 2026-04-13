// 0x800EB554 cXObjectImpl::GetObjectLightSource (44B)

struct EdithVariableSet {
    short* operator[](int index);
};

struct cXObj_GetObjectLightSource {
    char pad[0x28];
    EdithVariableSet m_vars;
    short GetObjectLightSource();
};

short cXObj_GetObjectLightSource::GetObjectLightSource() {
    return *m_vars[16];
}
