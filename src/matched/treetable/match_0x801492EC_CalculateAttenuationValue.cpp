// FLAGS: -O2 -fno-rtti
// 0x801492EC (196B) CalculateAttenuationValue(bool, int, float)

extern float g_sdata1;
extern float g_sdata2;
extern float g_sdata3;
extern float g_sdata4;
extern float g_sdata5;
extern float g_sdata6;

float CalculateAttenuationValue(bool flag, int type, float value) {
    if (flag) {
        switch (type) {
            case 0: return value;
            case 1: return 0.0f;
            case 2: return g_sdata1;
            case 3: return g_sdata2;
            case 4: return g_sdata3;
            default: return 0.02f;
        }
    } else {
        switch (type) {
            case 0: return value;
            case 1: return 0.0f;
            case 2: return g_sdata4;
            case 3: return g_sdata5;
            case 4: return g_sdata6;
            default: return 0.02f;
        }
    }
}
