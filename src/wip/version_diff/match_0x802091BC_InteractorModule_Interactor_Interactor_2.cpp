// InteractorModule::Interactor::Interactor(void) - 0x802091BC (196 bytes)
// Constructor with full field initialization

struct Interactor {
    int m_playerId;      // 0
    int m_field4;        // 4
    float m_posX;        // 8
    float m_posY;        // 12
    float m_posZ;        // 16
    float m_snappedX;    // 20
    float m_snappedY;    // 24
    float m_snappedZ;    // 28
    float m_field32;     // 32
    float m_field36;     // 36
    float m_field40;     // 40
    int m_field44;       // 44
    int m_field48;       // 48
    float m_field52;     // 52
    float m_field56;     // 56
    float m_field60;     // 60
    float m_field64;     // 64
    int m_field68;       // 68
    int m_field72;       // 72
    int m_field76;       // 76
    float m_extentX;     // 80
    float m_extentY;     // 84
    float m_field88;     // 88
    // vtable at 92

    Interactor(void);
};

extern float g_kZero;  // SDA constant

Interactor::Interactor(void) {
    m_playerId = 0;
    m_field4 = 0;
    m_posX = 0.0f;
    m_posY = 0.0f;
    m_posZ = 0.0f;
    m_snappedX = 0.0f;
    m_snappedY = 0.0f;
    m_snappedZ = 0.0f;
    m_field32 = 0.0f;
    m_field36 = 0.0f;
    m_field40 = 0.0f;
    m_field44 = 0;
    m_field48 = 0;
    m_field52 = 0.0f;
    m_field56 = 0.0f;
    m_field60 = 0.0f;
    m_field64 = 0.0f;
    m_field68 = 0;
    m_field72 = 0;
    m_extentX = 0.0f;
    m_extentY = 0.0f;
    m_field88 = 0.0f;
}
