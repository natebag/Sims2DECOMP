/* 0x8006EBDC (24 bytes) - SimImageMaker::SetModel(eBodyPartS2C, EIStaticModel *) */
class EIStaticModel;

class SimImageMaker {
public:
    char pad[0x90];
    EIStaticModel *m_models[1];
    void SetModel(int part, EIStaticModel *model);
};

void SimImageMaker::SetModel(int part, EIStaticModel *model) {
    if (part > 25) return;
    m_models[part] = model;
}
