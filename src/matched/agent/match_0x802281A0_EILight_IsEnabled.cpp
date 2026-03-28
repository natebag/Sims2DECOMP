struct EILight {
    char _pad[0x88];
    int m_IsEnabled;
    int IsEnabled();
};
int EILight::IsEnabled() { return m_IsEnabled; }
