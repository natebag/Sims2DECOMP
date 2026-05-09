// 0x801E7114 (56B) GetExposureHandler(void)
// Sister of GetTheExposureHandler @ 0x801AA580 — same fcmpu override pattern, different consts.

class EyeToyClient {
public:
    static float GetExposure();
};

extern float g_exposureCmpArr2[4];        // 0x803F818C
extern float g_exposureFallbackArr2[4];   // 0x803F8190

float GetExposureHandler()
{
    float v = EyeToyClient::GetExposure();
    if (v == g_exposureCmpArr2[0]) {
        v = g_exposureFallbackArr2[0];
    }
    return v;
}
