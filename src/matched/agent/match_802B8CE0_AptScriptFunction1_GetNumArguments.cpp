struct Inner_SF1NA {
    char pad[0x04];
    int m_numArgs;
};
struct AptSF1_GNA {
    char pad[0x34];
    Inner_SF1NA* m_inner;
    int GetNumArguments();
};
int AptSF1_GNA::GetNumArguments() {
    return m_inner->m_numArgs;
}
