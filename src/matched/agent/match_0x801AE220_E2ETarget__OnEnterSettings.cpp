// 0x801AE220 E2ETarget::OnEnterSettings(void) (36B)
// Inverse of SaveCurrentSettings — copy 4 SDA float statics into this+200..212.

extern float s_brightness;
extern float s_contrast;
extern float s_saturation;
extern float s_hue;

class E2ETarget {
public:
    char _pad[200];
    float m_brightness;
    float m_contrast;
    float m_saturation;
    float m_hue;
    void OnEnterSettings();
};

void E2ETarget::OnEnterSettings() {
    m_brightness = s_brightness;
    m_contrast = s_contrast;
    m_saturation = s_saturation;
    m_hue = s_hue;
}
