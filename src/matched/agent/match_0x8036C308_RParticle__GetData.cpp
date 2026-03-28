struct RParticle {
    char _p[0x14];
    int m_data;
    int GetData();
};
int RParticle::GetData() { return m_data; }
