// 0x80093170 MUStatesLoadConfig::Update(float) (64B)

class SimsMemCardWrap {
public:
    int LoadConfigFile();
};

class StateMachine {
public:
    int ReturnFromState(int n);
};

class MUStatesLoadConfig {
public:
    char pad0[8];
    StateMachine* m_machine;
    void Update(float dt);
};

extern char gMemCardWrapHolder_804858D8[16];

void MUStatesLoadConfig::Update(float dt) {
    ((SimsMemCardWrap*)(*(void**)gMemCardWrapHolder_804858D8))->LoadConfigFile();
    m_machine->ReturnFromState(2);
}
