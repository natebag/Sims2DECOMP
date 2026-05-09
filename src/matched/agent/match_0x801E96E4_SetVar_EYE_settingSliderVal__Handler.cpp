// 0x801E96E4 (60B) SetVar_EYE_settingSliderVal::Handler(char *)
// AtoF(arg); call function pointer at this+12 with the float.

extern "C" float AtoF(char* s);

class SetVar_EYE_settingSliderVal {
public:
    char _pad[12];
    void (*m_fn)(float);
    void Handler(char* arg);
};

void SetVar_EYE_settingSliderVal::Handler(char* arg)
{
    float v = AtoF(arg);
    m_fn(v);
}
