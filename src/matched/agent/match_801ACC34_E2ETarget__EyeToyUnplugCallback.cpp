class E2ETarget {
public:
    char _pad[0x8C];
    int m_unplugged;

    void OnEyeToyUnplugged(void);
    static void EyeToyUnplugCallback(int status);
};

static E2ETarget* s_e2eTarget;

void E2ETarget::EyeToyUnplugCallback(int status) {
    s_e2eTarget->m_unplugged = 1;
    s_e2eTarget->OnEyeToyUnplugged();
}
