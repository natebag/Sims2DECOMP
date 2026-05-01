// 0x803044E4 EController::VibrateMotorOne(float, float) (80B)

class ECVt {
public:
    char pad[0x28];
    short m_off;                          // 0x28
    char _p[2];
    int (*m_fn)(void*, float);            // 0x2C
};

class EController {
public:
    char pad_00[0x1E4];
    float m_intensity;                    // 0x1E4
    char pad_e8[0x204 - 0x1E8];
    void* m_handle;                       // 0x204
    ECVt* m_vt_motor;                     // 0x208

    int VibrateMotorOne(float duration, float intensity);
};

int EController::VibrateMotorOne(float duration, float intensity) {
    if (m_handle == 0) return 0;
    m_intensity = intensity;
    ECVt* vt = m_vt_motor;
    short off = vt->m_off;
    int (*fn)(void*, float) = vt->m_fn;
    return fn((char*)this + off, duration);
}
