// 0x802FACD4 (92B) ESubModel::DelRefSubResources(void)

struct ESubModelShader_DRS {
    char pad[112];
    void DelRefSubResources(void);
};

struct ESubModel_DRS {
    ESubModelShader_DRS *shaders;
    int count;
    void DelRefSubResources(void);
};

void ESubModel_DRS::DelRefSubResources(void) {
    for (int i = 0; i < count; i++) {
        shaders[i].DelRefSubResources();
    }
}
