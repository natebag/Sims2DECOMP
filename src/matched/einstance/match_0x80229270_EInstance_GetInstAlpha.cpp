// 0x80229270 EInstance::GetInstAlpha (20B) — indexed float at +96

extern int g_instAlphaIdx;  // SDA at -28496(r13)

struct EInstance {
    char pad[96];
    float m_alphas[1];
    float GetInstAlpha();
};

float EInstance::GetInstAlpha() {
    return m_alphas[g_instAlphaIdx];
}
