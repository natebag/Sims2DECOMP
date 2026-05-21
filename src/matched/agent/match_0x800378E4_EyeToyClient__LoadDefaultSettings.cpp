// 0x800378E4 EyeToyClient::LoadDefaultSettings() (76B)

extern char g_default_const_803D1644[16];
extern char g_exposure_const_803D1648[16];

class EyeToyClient {
public:
    static void SetSaturation(float);
    static void SetBrightness(float);
    static void SetHue(float);
    static void SetExposure(float);
    static void LoadDefaultSettings();
};

void EyeToyClient::LoadDefaultSettings() {
    EyeToyClient::SetSaturation(*(volatile float*)g_default_const_803D1644);
    EyeToyClient::SetBrightness(*(volatile float*)g_default_const_803D1644);
    EyeToyClient::SetHue(*(volatile float*)g_default_const_803D1644);
    EyeToyClient::SetExposure(*(volatile float*)g_exposure_const_803D1648);
}
