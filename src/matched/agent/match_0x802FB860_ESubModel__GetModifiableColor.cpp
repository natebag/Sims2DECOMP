// 0x802FB860 (128B) ESubModel::GetModifiableColor(unsigned int)
// Loop over ESubModelShader array at offsets 0/4, stride 112.

struct ESubModelShader_SMG {
    char pad[112];
    int CanColorBeModified(void);
    int GetModifiableColor(unsigned int);
};

struct ESubModel_SMG {
    ESubModelShader_SMG *shaders;
    int count;
    int GetModifiableColor(unsigned int colorIndex);
};

int ESubModel_SMG::GetModifiableColor(unsigned int colorIndex) {
    for (int i = 0; i < count; i++) {
        if (shaders[i].CanColorBeModified()) {
            return shaders[i].GetModifiableColor(colorIndex);
        }
    }
    return 0;
}
