// 0x801AA580 (56B) GetTheExposureHandler(void)
// Calls EyeToyClient::GetExposure(); if result == const1, override with const2.

class EyeToyClient {
public:
    static float GetExposure();
};

extern float g_exposureCmpArr[4];        // 0x803EF1CC
extern float g_exposureFallbackArr[4];   // 0x803EF1D0

float GetTheExposureHandler()
{
    float v = EyeToyClient::GetExposure();
    if (v == g_exposureCmpArr[0]) {
        v = g_exposureFallbackArr[0];
    }
    return v;
}
