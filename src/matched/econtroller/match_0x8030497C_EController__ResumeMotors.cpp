// 0x8030497C EController::ResumeMotors(void) (72B)

class ECRMVt {
public:
    char pad[0x50];
    short m_off;                                                      // 0x50
    char _p[2];
    void (*m_fn)(void*, float, float, float, float);                  // 0x54
};

class EController {
public:
    char pad_00[0x1EC];
    float m_f1;                                                       // 0x1EC
    float m_f2;                                                       // 0x1F0
    float m_f3;                                                       // 0x1F4
    float m_f4;                                                       // 0x1F8
    char pad2[0x208 - 0x1FC];
    ECRMVt* m_vt;                                                     // 0x208

    void ResumeMotors();
};

void EController::ResumeMotors() {
    ECRMVt* vt = m_vt;
    short off = vt->m_off;
    void (*fn)(void*, float, float, float, float) = vt->m_fn;
    fn((char*)this + off, m_f1, m_f2, m_f3, m_f4);
}
