// 0x801B0B18 FAMTarget::UpdateTempShaders() (96B)

class UIReflow {
public:
    char data[24];
    UIReflow();
    ~UIReflow();
    void ResetPosition(char* name, int p2, int p3, int p4);
};

extern char g_str_temp_shaders[16];

class FAMTarget {
public:
    char pad[0x14C];
    int m_14C;
    void UpdateTempShaders();
};

void FAMTarget::UpdateTempShaders() {
    int adj = m_14C * 80 + 100;
    UIReflow reflow;
    reflow.ResetPosition(g_str_temp_shaders, 100, adj, 0);
}
