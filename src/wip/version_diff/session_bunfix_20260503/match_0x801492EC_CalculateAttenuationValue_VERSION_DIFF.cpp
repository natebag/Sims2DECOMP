// FLAGS: -fno-rtti
// 0x801492EC (196B) CalculateAttenuationValue(bool, int, float)

extern float g_sdata1;
extern float g_sdata2;
extern float g_sdata3;
extern float g_sdata4;
extern float g_sdata5;
extern float g_sdata6;
extern float g_const1;
extern float g_const2;

float CalculateAttenuationValue(bool flag, int type, float value) {
    switch (type) {
        case 0: return value;
        case 1: return g_const1;
        case 2: return flag ? g_sdata1 : g_sdata4;
        case 3: return flag ? g_sdata2 : g_sdata5;
        case 4: return flag ? g_sdata3 : g_sdata6;
        default: return g_const2;
    }
}
