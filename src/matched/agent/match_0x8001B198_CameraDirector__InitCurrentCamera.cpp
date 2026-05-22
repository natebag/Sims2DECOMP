// FLAGS: -fno-schedule-insns
// 0x8001B198 CameraDirector::InitCurrentCamera() (100B)

class EMat4 {
public:
    static void Id(void* m);
};

class CameraDirector {
public:
    char pad[0x80];
    char m_80_mat[0x40];
    char padC0[0x58];
    void* m_118;
    void* m_11C;
    char pad120[0x80];
    float m_1A0;
    char pad1A4[0x7C];
    void* m_220;
    float m_224;
    float m_228;
    float m_22C;
    int m_230;
    void InitSimsCamera();
    void InitCurrentCamera();
};

void CameraDirector::InitCurrentCamera() {
    InitSimsCamera();
    EMat4::Id(m_80_mat);
    void* zero_p = 0;
    m_230 = 1;
    m_228 = 0.0f;
    m_220 = zero_p;
    m_1A0 = 0.0f;
    m_118 = zero_p;
    m_11C = zero_p;
    m_22C = 0.0f;
    m_224 = 0.0f;
}
