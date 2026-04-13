struct REffectsEmitter {
    char _p[0x14];
    int m_val;
    int GetEmitterInitData();
};
int REffectsEmitter::GetEmitterInitData() { return m_val; }
