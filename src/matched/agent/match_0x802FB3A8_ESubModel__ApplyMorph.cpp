// 0x802FB3A8 (96B) ESubModel::ApplyMorph(void)

struct ESubModelShader_AM {
    char pad[112];
    void ApplyMorph(void);
};

struct ESubModel_AM {
    ESubModelShader_AM *shaders;
    int count;
    int ApplyMorph(void);
};

int ESubModel_AM::ApplyMorph(void) {
    for (int i = 0; i < count; i++) {
        shaders[i].ApplyMorph();
    }
    return 1;
}
