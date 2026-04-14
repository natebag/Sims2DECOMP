// 0x800EB10C cXObjectImpl::GetModule (8B)

struct cXObj_GetModule {
    char pad[0x58];
    int m_val;
    int GetModule();
};

int cXObj_GetModule::GetModule() {
    return m_val;
}
