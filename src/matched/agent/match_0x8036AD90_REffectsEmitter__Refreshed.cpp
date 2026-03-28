struct REffectsEmitter {
    char _p[0x20];
    int m_val;
    int Refreshed();
};
int REffectsEmitter::Refreshed() { return m_val; }
