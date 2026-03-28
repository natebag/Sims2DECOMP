static float s_brightness;
static float s_contrast;
static float s_saturation;
static float s_hue;

class E2ETarget {
public:
    char _pad[0xC8];
    float m_savedBrightness;
    float m_savedContrast;
    float m_savedSaturation;
    float m_savedHue;

    void OnEnterSettings(void);
};

void E2ETarget::OnEnterSettings(void) {
    m_savedBrightness = s_brightness;
    m_savedContrast = s_contrast;
    m_savedSaturation = s_saturation;
    m_savedHue = s_hue;
}
