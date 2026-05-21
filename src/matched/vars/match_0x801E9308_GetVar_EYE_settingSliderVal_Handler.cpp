// 0x801E9308 GetVar_EYE_settingSliderVal::Handler(char*) (72B)

extern char s_floatFmt[];   // 0x803F87A0
extern int Sprintf(char* buf, char* fmt, ...);

class GetVar_EYE_settingSliderVal {
public:
    char pad_00[12];
    float (*m_callback)();
    int Handler(char* dst);
};

int GetVar_EYE_settingSliderVal::Handler(char* dst) {
    float v = m_callback();
    return Sprintf(dst, s_floatFmt, v);
}
