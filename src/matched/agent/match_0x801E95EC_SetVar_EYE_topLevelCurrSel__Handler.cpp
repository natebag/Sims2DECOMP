// 0x801E95EC SetVar_EYE_topLevelCurrSel::Handler(char*) (92B)

extern "C" int AtoI(char* s);

class EyeToyClient {
public:
    static void SetHue(float v);
    static void SetBrightness(float v);
    static void SetSaturation(float v);
    static void RestoreDefaults();
};

extern char g_eye_const_803F87A8[16];
extern void* g_eyeToyMgr_SDA;

class SetVar_EYE_topLevelCurrSel {
public:
    void Handler(char* val);
};

void SetVar_EYE_topLevelCurrSel::Handler(char* val) {
    int n = AtoI(val);
    *(int*)((char*)g_eyeToyMgr_SDA + 152) = n;
    if (n == 1) {
        EyeToyClient::SetHue(*(volatile float*)g_eye_const_803F87A8);
        EyeToyClient::SetBrightness(*(volatile float*)g_eye_const_803F87A8);
        EyeToyClient::SetSaturation(*(volatile float*)g_eye_const_803F87A8);
        EyeToyClient::RestoreDefaults();
    }
}
