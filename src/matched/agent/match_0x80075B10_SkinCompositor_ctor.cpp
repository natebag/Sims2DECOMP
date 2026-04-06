// SkinCompositor constructor
// 96 bytes, initializes fields then calls Init function

class SkinCompositor {
    short m_field0;      // offset 0
    char pad[2];
    int m_fields[8];     // offset 4-32
    int m_field24;       // offset 36
public:
    void Init();
    SkinCompositor();
};

void SkinCompositor::Init() {
    // initialization
}

SkinCompositor::SkinCompositor() {
    this->m_field24 = 0;
    this->m_field0 = 256;
    for (int i = 0; i < 8; i++) {
        this->m_fields[i] = 0;
    }
    this->Init();
}
