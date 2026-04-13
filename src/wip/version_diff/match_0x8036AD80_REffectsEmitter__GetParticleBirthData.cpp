struct REffectsEmitter {
    char _p[0x18];
    int m_val;
    int GetParticleBirthData();
};
int REffectsEmitter::GetParticleBirthData() { return m_val; }
