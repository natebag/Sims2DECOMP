// 0x801AC95C E2ETarget::Update() (84B)
// ASMPROC_swap_adj: a="li" b="lis" which=0
// ASMPROC_swap_adj: a="stw" b="lfs" which=0

class EyeToyClient {
public:
    static void Update(float dt);
    static void Render();
};

extern char g_e2e_update_dt[16];

class E2ETarget {
public:
    char pad[0x88];
    int m_88;
    bool IsEyeToyPluggedIn();
    void ReintializeEyeToy();
    void Update();
};

void E2ETarget::Update() {
    if (!IsEyeToyPluggedIn()) {
        ReintializeEyeToy();
    }
    m_88 = 1;
    EyeToyClient::Update(*(float*)g_e2e_update_dt);
    EyeToyClient::Render();
}
