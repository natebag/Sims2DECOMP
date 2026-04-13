// 0x8035768C MotionBlur::SetTargetSettings (32b)

struct MotionBlurSettings {
    int f00, f04, f08;
};

struct MotionBlur {
    char pad[0x14];
    MotionBlurSettings m_target;
    void SetTargetSettings(MotionBlurSettings& settings);
};

void MotionBlur::SetTargetSettings(MotionBlurSettings& settings) {
    m_target = settings;
}
