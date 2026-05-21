// 0x800AA050 AmbientSoundPlayer::UpdateSoundPosition(void) (84B)
// TRIAGE: Held during fleet git-coordination — analysis only.

extern float g_deltaTime;  // SDA -26800

class SomeObj {
public:
    char pad[25];
    unsigned char m_flag;
};

class AmbientSoundPlayer {
public:
    char pad_00[4];
    SomeObj* m_obj;
    char pad_08[12];
    float m_posX;
    float m_posY;
    char pad_28[4];
    float m_velX;
    float m_velY;
    void UpdateSoundPosition();
    void UpdateLoopingSoundPosition();
};

void AmbientSoundPlayer::UpdateSoundPosition() {
    float dt = g_deltaTime;
    m_posX = m_velX * dt + m_posX;
    m_posY = m_velY * dt + m_posY;
    if (m_obj->m_flag & 1) {
        UpdateLoopingSoundPosition();
    }
}
