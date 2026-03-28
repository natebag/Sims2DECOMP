struct EDataHeader {
    char _p[0x08];
    unsigned int m_signature;
    int VerifySignature(unsigned int sig);
};
int EDataHeader::VerifySignature(unsigned int sig) { return sig == m_signature; }
