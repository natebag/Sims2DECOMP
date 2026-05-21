// 0x801AD3E8 E2ETarget::UpdateSaturation(char *, char *) (112B)

class EyeToyClient {
public:
    static void SetSaturation(float h);
};

class E2ETarget {
public:
    void SaveCurrentSettings(char* a, char* b);
    void UpdateSaturation(char* a, char* b);
};

extern "C" float AtoF(char* s);

void E2ETarget::UpdateSaturation(char* a, char* b) {
    float v = AtoF(b);
    if (v >= 1.0f) v = 1.0f;
    else if (v <= 0.0f) v = 0.0f;
    EyeToyClient::SetSaturation(v);
    SaveCurrentSettings(0, 0);
}
