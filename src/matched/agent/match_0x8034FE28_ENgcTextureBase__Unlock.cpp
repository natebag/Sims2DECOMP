struct ENgcTextureBase {
    char _p[0x44];
    int m_lockCount;
    void Unlock();
};
void ENgcTextureBase::Unlock() { m_lockCount--; }
