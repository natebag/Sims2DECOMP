// ASMPROC_swap_adj: a=stfs b=stfs which=1
// ASMPROC_swap_adj: a=stfs b=stfs which=2
// ASMPROC_swap_adj: a=stw b=stfs which=1
// ASMPROC_swap_adj: a=stw b=stfs which=1
// 0x800A9270 AmbientSoundPlayer::AmbientSoundPlayer(void) (76 B)
extern float kAmbientSoundPlayerZero[4];  // 0.0f at 0x803D91F4

struct AmbientSoundPlayer {
    int m_i0;     // 0x00
    int m_i4;     // 0x04
    int m_i8;     // 0x08
    int m_iC;     // 0x0C
    int m_i10;    // 0x10
    float m_f14;  // 0x14
    float m_f18;  // 0x18
    float m_f1C;  // 0x1C
    float m_f20;  // 0x20
    float m_f24;  // 0x24
    int m_i28;    // 0x28
    int m_i2C;    // 0x2C
    AmbientSoundPlayer();
};

AmbientSoundPlayer::AmbientSoundPlayer() {
    float zero = kAmbientSoundPlayerZero[0];
    m_i0 = 0;
    float* p = &m_f14;
    m_i4 = 0;
    m_i8 = 0;
    m_iC = 0;
    m_i10 = 0;
    m_f14 = zero;
    p[2] = zero;
    p[1] = zero;
    m_f24 = zero;
    m_i28 = 0;
    m_i2C = -1;
    m_f20 = zero;
}
