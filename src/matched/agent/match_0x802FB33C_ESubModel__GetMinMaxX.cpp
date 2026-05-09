// 0x802FB33C (108B) ESubModel::GetMinMaxX(float *, float *)
// Simple loop over ESubModelShader array (offsets 0/4, stride 112).

struct ESubModelShader_GMX {
    char pad[112];
    void GetMinMaxX(float *pMin, float *pMax);
};

struct ESubModel_GMX {
    ESubModelShader_GMX *shaders;
    int count;
    void GetMinMaxX(float *pMin, float *pMax);
};

void ESubModel_GMX::GetMinMaxX(float *pMin, float *pMax) {
    for (int i = 0; i < count; i++) {
        shaders[i].GetMinMaxX(pMin, pMax);
    }
}
