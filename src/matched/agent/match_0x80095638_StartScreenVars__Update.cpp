// 0x80095638 (68B) StartScreenVars::Update(float)

extern const float lbl_803D8790[3];

struct StartScreenVars {
    float m_field_0;   // 0x00
    char pad_4[4];     // 0x04
    float m_field_8;   // 0x08
    int m_field_c;     // 0x0C
    void Update(float dt);
};

void StartScreenVars::Update(float dt) {
    m_field_0 += dt;
    m_field_8 += dt;
    if (m_field_8 >= lbl_803D8790[0]) {
        m_field_8 -= lbl_803D8790[0];
        m_field_c ^= 1;
    }
}
