struct Emitter {
    char _pad[0x7C];
    int m_Get;
    int Get();
};
int Emitter::Get() { return m_Get; }
