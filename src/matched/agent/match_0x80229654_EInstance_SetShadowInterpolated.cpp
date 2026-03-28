struct EInstance {
    char _pad[0x0C];
    int m_SetShadowInterpolated;
    void SetShadowInterpolated(int val);
};
void EInstance::SetShadowInterpolated(int val) { m_SetShadowInterpolated = val; }
