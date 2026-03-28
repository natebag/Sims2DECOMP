class EyeToyClient {
public:
    static void SetHue(float val);
    static void SetBrightness(float val);
    static void SetExposure(float val);
    static void SetSaturation(float val);
};

class E2ETarget {
public:
    static float s_savedHue;
    static float s_savedSaturation;
    static float s_savedBrightness;
    static float s_savedExposure;

    void RestorePreviousSettings(void);
};

void E2ETarget::RestorePreviousSettings(void) {
    EyeToyClient::SetHue(s_savedHue);
    EyeToyClient::SetBrightness(s_savedBrightness);
    EyeToyClient::SetExposure(s_savedExposure);
    EyeToyClient::SetSaturation(s_savedSaturation);
}
