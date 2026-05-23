// 0x801ACF0C E2ETarget::InitializeEyeToy(void) (104B)

class EyeToyClient {
public:
    static int OpenSession();
    static void SetUnplugCallback(void (*cb)(int));
    static void StartStream();
};

class E2ETarget {
public:
    char _pad0[140];
    int m_state;
    int InitializeEyeToy();
};

extern void E2ETarget_OnUnplugged(int);

int E2ETarget::InitializeEyeToy() {
    int result = 0;
    if (EyeToyClient::OpenSession()) {
        EyeToyClient::SetUnplugCallback(E2ETarget_OnUnplugged);
        EyeToyClient::StartStream();
        m_state = 0;
        result = 1;
    } else {
        EyeToyClient::SetUnplugCallback(0);
        m_state = 1;
    }
    return result;
}
