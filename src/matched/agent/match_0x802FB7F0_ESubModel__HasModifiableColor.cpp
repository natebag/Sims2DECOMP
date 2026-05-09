// 0x802FB7F0 (112B) ESubModel::HasModifiableColor(void)
// Loop over ESubModelShader array at offsets 0/4, stride 112.

struct ESubModelShader_SMH {
    char pad[112];
    int CanColorBeModified(void);
};

struct ESubModel_SMH {
    ESubModelShader_SMH *shaders;
    int count;
    int HasModifiableColor(void);
};

int ESubModel_SMH::HasModifiableColor(void) {
    for (int i = 0; i < count; i++) {
        if (shaders[i].CanColorBeModified()) return 1;
    }
    return 0;
}
