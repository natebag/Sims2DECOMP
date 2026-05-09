// 0x802FAC50 (56B) ESubModel::ESubModel(void)
// TArrayERModelAllocator adds 8B to TArray's 12B base → 20B total before m_20.

struct TArray_ESubModelShader {
    char pad[20];
    TArray_ESubModelShader();
};

struct ESubModel_CTOR {
    TArray_ESubModelShader shaders;
    int m_20;
    ESubModel_CTOR();
};

ESubModel_CTOR::ESubModel_CTOR() {
    m_20 = 0;
}
