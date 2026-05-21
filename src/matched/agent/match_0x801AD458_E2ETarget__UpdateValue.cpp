// 0x801AD458 E2ETarget::UpdateValue(char *, char *) (112B)
// Note: UpdateValue calls EyeToyClient::SetBrightness

class EyeToyClient {
public:
    static void SetBrightness(float h);
};

class E2ETarget {
public:
    void SaveCurrentSettings(char* a, char* b);
    void UpdateValue(char* a, char* b);
};

extern "C" float AtoF(char* s);

void E2ETarget::UpdateValue(char* a, char* b) {
    float v = AtoF(b);
    if (v >= 1.0f) v = 1.0f;
    else if (v <= 0.0f) v = 0.0f;
    EyeToyClient::SetBrightness(v);
    SaveCurrentSettings(0, 0);
}
