static float s_savedHue;
static float s_savedSaturation;
static float s_savedBrightness;
static float s_savedExposure;

void EyeToyClient_LoadDefaultSettings(void);
float EyeToyClient_GetHue(void);
float EyeToyClient_GetSaturation(void);
float EyeToyClient_GetBrightness(void);
float GetTheExposureHandler(void);

class E2ETarget {
public:
    void SetDefault(char* a, char* b);
};

void E2ETarget::SetDefault(char* a, char* b) {
    EyeToyClient_LoadDefaultSettings();
    s_savedHue = EyeToyClient_GetHue();
    s_savedSaturation = EyeToyClient_GetSaturation();
    s_savedBrightness = EyeToyClient_GetBrightness();
    s_savedExposure = GetTheExposureHandler();
}
