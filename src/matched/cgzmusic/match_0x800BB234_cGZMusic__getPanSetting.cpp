// 0x800BB234 cGZMusic::getPanSetting() (68B)

extern char g_panSetting_magic[16];
extern char g_panSetting_scale[16];

class cGZMusic {
public:
    char pad[0x18];
    int m_18;
    float getPanSetting();
};

float cGZMusic::getPanSetting() {
    int x = m_18 - 0x200;
    return (float)x * (*(float*)g_panSetting_scale);
}
