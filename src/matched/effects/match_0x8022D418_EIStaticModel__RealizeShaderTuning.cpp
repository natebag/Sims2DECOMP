// 0x8022D418 EIStaticModel::RealizeShaderTuning(void) (100B)

class EInstance {};

class ERLevel {
public:
    void RemoveInstanceFromRoom(EInstance* inst);
    void AddInstanceToRoom(EInstance* inst);
};

class EIStaticModel : public EInstance {
    ERLevel* m_erLevel;
public:
    void RealizeShaderTuning();
};

void EIStaticModel::RealizeShaderTuning() {
    char* vt = *(char**)this;
    short adj = *(short*)(vt + 0xa0);
    void (*fn)(void*) = *(void(**)(void*))(vt + 0xa4);
    fn((char*)this + adj);
    ERLevel* er = m_erLevel;
    if (er) {
        er->RemoveInstanceFromRoom((EInstance*)this);
        er->AddInstanceToRoom((EInstance*)this);
    }
}
