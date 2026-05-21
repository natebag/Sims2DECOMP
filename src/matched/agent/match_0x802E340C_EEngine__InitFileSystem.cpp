// 0x802E340C EEngine::InitFileSystem(void) (44B)

class ENgcFileSystem {
public:
    char m_pad[256];
    void Init(int deviceType);
};

extern ENgcFileSystem g_ngcFileSystem;

class EEngine {
public:
    static void InitFileSystem();
};

void EEngine::InitFileSystem() {
    g_ngcFileSystem.Init(0x80000000);
}
