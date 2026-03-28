struct ELightGrid {
    char pad0[16];
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;

    void EvaluateLamps(void);
    void EvaluateAmbientAndDirectionalLights(int, int);
    void EvaluatePortalLights(int, int);
};

void ELightGrid::EvaluateLamps(void) {
    EvaluateAmbientAndDirectionalLights(m_field18, m_field1C);
    EvaluatePortalLights(m_field10, m_field14);
}
