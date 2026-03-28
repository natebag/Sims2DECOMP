struct EILight {
    char _pad[0x88];
    int m_Enable;
    void Enable(int val);
};
void EILight::Enable(int val) { m_Enable = val; }
