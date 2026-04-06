// SkinCompositor::FinalizeSkinTexture(void)
// 76 bytes, conditional with 2 different bl calls

class InnerStruct {
public:
    char pad[20];
    int m_field14;  // offset 20
};

class SkinCompositor {
    char pad[4];
    int m_field4;      // offset 4
    int m_field8;      // offset 8
    char pad2[12];
    InnerStruct* m_inner;  // offset 24
public:
    void FinalizeSkinTexture();
};

// External functions at different addresses
extern "C" void sub_8030B228(int, int);
extern "C" void sub_8030B7B0(int, int);

void SkinCompositor::FinalizeSkinTexture() {
    if (this->m_field4 != 0) {
        sub_8030B228(this->m_field8, this->m_inner->m_field14);
    } else {
        sub_8030B7B0(this->m_field8, this->m_inner->m_field14);
    }
}
