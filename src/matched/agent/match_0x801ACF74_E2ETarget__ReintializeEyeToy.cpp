// 0x801ACF74 E2ETarget::ReintializeEyeToy() (84B)

class EyeToyClient {
public:
    typedef void (*UnplugCallback)(int);
    static void SetUnplugCallback(UnplugCallback cb);
    static void StopStream();
    static void CloseSession();
};

class UIDialog {
public:
    void HideDialog();
};

class E2ETarget {
public:
    char pad[0x8C];
    int m_8C;
    char pad90[0x54];
    UIDialog m_E4_dialog;
    void InitializeEyeToy();
    void ReintializeEyeToy();
};

void E2ETarget::ReintializeEyeToy() {
    EyeToyClient::SetUnplugCallback(0);
    EyeToyClient::StopStream();
    EyeToyClient::CloseSession();
    InitializeEyeToy();
    if (m_8C == 0) {
        m_E4_dialog.HideDialog();
    }
}
