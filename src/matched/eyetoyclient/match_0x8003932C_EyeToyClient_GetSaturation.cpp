// 0x8003932C EyeToyClient::GetSaturation (24b)
// FLAGS: -fno-schedule-insns
extern float g_saturationTable[3];  /* 3-elem forces lis+lfs */
extern float g_saturationScale[3];  /* 3-elem forces lis+lfs */

struct EyeToyClient {
    static float GetSaturation();
};

float EyeToyClient::GetSaturation() {
    return g_saturationTable[0] * g_saturationScale[0];
}
