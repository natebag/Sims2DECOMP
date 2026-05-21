// 0x801AD378 E2ETarget::UpdateHue(char *, char *) (112B)

class EyeToyClient {
public:
    static void SetHue(float h);
};

class E2ETarget {
public:
    void SaveCurrentSettings(char* a, char* b);
    void UpdateHue(char* a, char* b);
};

extern "C" float AtoF(char* s);

void E2ETarget::UpdateHue(char* a, char* b) {
    float v = AtoF(b);
    if (v >= 1.0f) v = 1.0f;
    else if (v <= 0.0f) v = 0.0f;
    EyeToyClient::SetHue(v);
    SaveCurrentSettings(0, 0);
}
