// 0x801E8F60 (52B) EYETarget::Update(void)
// Sets m_field_0C0 = 1, then ticks EyeToyClient with a fixed float argument,
// then renders. The float constant lives in .rodata; compiler emits lis+lfs
// offset pair.

extern const float kEyeToyConsts[3];

class EyeToyClient {
public:
    static void Update(float);
    static void Render(void);
};

class EYETarget {
public:
    char pad_000[0xC0];
    int m_field_0C0;
    void Update(void);
};

void EYETarget::Update(void) {
    m_field_0C0 = 1;
    EyeToyClient::Update(kEyeToyConsts[0]);
    EyeToyClient::Render();
}
