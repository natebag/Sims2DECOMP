// 0x80039434 EyeToyClient::GetBrightness (24b)
extern float g_brightnessTable[3];  /* 3-elem forces lis+lfs */
extern float g_brightnessScale[3];  /* 3-elem forces lis+lfs */

struct EyeToyClient {
    static float GetBrightness();
};

float EyeToyClient::GetBrightness() {
    return g_brightnessTable[0] * g_brightnessScale[0];
}
