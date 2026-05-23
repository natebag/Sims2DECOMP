// 0x8022922C EInstance::SetInstAlpha(float) (68B)
extern int _instanceContext;
extern float g_min_8022922C[];
extern float g_max_8022922C[];

class EInstance {
public:
    char pad[96];
    float m_instAlphas[4];
    void SetInstAlpha(float alpha);
};

void EInstance::SetInstAlpha(float alpha) {
    if (alpha <= g_min_8022922C[0]) alpha = g_min_8022922C[0];
    if (alpha >= g_max_8022922C[0]) alpha = g_max_8022922C[0];
    m_instAlphas[_instanceContext] = alpha;
}
