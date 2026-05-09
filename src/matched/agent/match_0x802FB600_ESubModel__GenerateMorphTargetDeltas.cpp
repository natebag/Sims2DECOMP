// 0x802FB600 (120B) ESubModel::GenerateMorphTargetDeltas(ESubModel *)

struct ESubModelShader_GMD {
    char pad[112];
    void GenerateMorphTargetDeltas(ESubModelShader_GMD *target);
};

struct ESubModel_GMD {
    ESubModelShader_GMD *shaders;
    int count;
    void GenerateMorphTargetDeltas(ESubModel_GMD *target);
};

void ESubModel_GMD::GenerateMorphTargetDeltas(ESubModel_GMD *target) {
    if (target == 0) return;
    if (target->count != count) return;
    for (int i = 0; i < count; i++) {
        shaders[i].GenerateMorphTargetDeltas(&target->shaders[i]);
    }
}
