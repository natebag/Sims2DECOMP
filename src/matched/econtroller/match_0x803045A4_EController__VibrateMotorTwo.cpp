// 0x803045A4 EController::VibrateMotorTwo(float, float) (80B)

class EC2Vt {
public:
    char pad[0x38];
    short m_off;                          // 0x38
    char _p[2];
    int (*m_fn)(void*, float);            // 0x3C
};

class EController {
public:
    char pad_00[0x1E8];
    float m_intensity2;                   // 0x1E8
    char pad_e8[0x204 - 0x1EC];
    void* m_handle;                       // 0x204
    EC2Vt* m_vt_motor;                    // 0x208

    int VibrateMotorTwo(float duration, float intensity);
};

int EController::VibrateMotorTwo(float duration, float intensity) {
    if (m_handle == 0) return 0;
    m_intensity2 = intensity;
    EC2Vt* vt = m_vt_motor;
    short off = vt->m_off;
    int (*fn)(void*, float) = vt->m_fn;
    return fn((char*)this + off, duration);
}
