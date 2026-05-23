// 0x801AD5A8 E2ETarget::UpdateExposure(char *, char *) (112B)

class EyeToyClient {
public:
    static void SetExposure(float h);
};

class E2ETarget {
public:
    void SaveCurrentSettings(char* a, char* b);
    void UpdateExposure(char* a, char* b);
};

extern "C" float AtoF(char* s);

void E2ETarget::UpdateExposure(char* a, char* b) {
    float v = AtoF(b);
    if (v >= 1.0f) v = 1.0f;
    else if (v <= 0.0f) v = 0.0f;
    EyeToyClient::SetExposure(v);
    SaveCurrentSettings(0, 0);
}
