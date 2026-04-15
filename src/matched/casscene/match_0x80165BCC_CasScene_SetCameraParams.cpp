// FLAGS: -fno-schedule-insns
// 0x80165BCC CasScene::SetCameraParams(float, float, float) (16B)

struct CasScene {
    char pad[2748];
    float m_a;          // +2748
    char pad2[80];      // 2752..2831
    float m_b;          // +2832
    float m_c;          // +2836
    void SetCameraParams(float a, float b, float c);
};

void CasScene::SetCameraParams(float a, float b, float c) {
    m_c = c;
    m_a = a;
    m_b = b;
}
