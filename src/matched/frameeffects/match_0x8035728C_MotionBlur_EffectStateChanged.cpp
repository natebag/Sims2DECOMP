// 0x8035728C MotionBlur::EffectStateChanged (52b)
// FLAGS: -fno-elide-constructors

struct MotionBlurSettings { int f00, f04, f08; };

struct MotionBlur {
    char pad[0x20];
    MotionBlurSettings m_source;
    MotionBlurSettings m_target;
    void EffectStateChanged(int state);
};

void MotionBlur::EffectStateChanged(int state) {
    if (state != 2 && state != 8) return;
    m_target = m_source;
}
