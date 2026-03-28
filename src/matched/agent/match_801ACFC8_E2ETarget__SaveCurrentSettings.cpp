static float s_brightness;
static float s_contrast;
static float s_saturation;
static float s_hue;

float EyeToyClient_GetHue(void);
float EyeToyClient_GetSaturation(void);
float EyeToyClient_GetBrightness(void);
float GetTheExposureHandler(void);

class E2ETarget {
public:
    void SaveCurrentSettings(char* a, char* b);
};

void E2ETarget::SaveCurrentSettings(char* a, char* b) {
    s_brightness = EyeToyClient_GetHue();
    s_contrast = EyeToyClient_GetSaturation();
    s_saturation = EyeToyClient_GetBrightness();
    s_hue = GetTheExposureHandler();
}
